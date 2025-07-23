// Mustafa ESEN
//19010011047

#include "dialog.h"
#include "ui_dialog.h"
#include "buttons.h"

int sure = 0, kontrol = 0, suresayac = 30, kesilen_karpuz = 1;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->label_arkaplan->setGeometry(0, 100, 2000, 1100);

    ui->labelsure->setGeometry(25, 20, 60, 20);
    ui->labelsure_deger->setGeometry(80, 20, 60, 20);
    ui->labelkesilenkarpuz->setGeometry(900, 10, 400, 20);
    ui->labelkesilenkarpuz_sayisi->setGeometry(1100, 10, 400, 20);
    ui->labelkacankarpuz->setGeometry(900, 40, 400, 20);
    ui->labelkacankarpuz_sayisi->setGeometry(1100, 40, 400, 20);



    QTimer *timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, &Dialog::karpuzOlustur);

    QTimer *timer2 = new QTimer(this);
    timer2->start(1000);
    connect(timer2, &QTimer::timeout, this, &Dialog::zamanlayıcı);


}
int kesilen_karpuzkntrl = 0, kacan_karpuz = 1, kacan_karpuzkntrl = 0;

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::karpuzOlustur()
{
    if (suresayac < 0) {
        return; }
    int x=0;
    bool ok;
    QString path = "/home/esen/Masaüstü/19010011047_odev_1/konumlar.txt";

    QList<QStringList> veriListesi;
    QFile dosya(path);
    if (!dosya.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Dosya açılamadı.";
    }

    QTextStream okuyucu(&dosya);
    while (!okuyucu.atEnd())
    {
        QString satir = okuyucu.readLine();
        QStringList koordinatlar = satir.split(" ");
        veriListesi.append(koordinatlar);

    }

    dosya.close();

    if (kontrol % 10 == 0) {
        buttons *buttonn = new buttons(this);

        for (int j = 0; j < silinecek.size(); j++) {
            btns[silinecek[j]]->setVisible(false);
        }

        if (kesilen_karpuzkntrl) {
            ui->labelkesilenkarpuz_sayisi->setText(QString::number(kesilen_karpuz));
            kesilen_karpuz += 1;
            kesilen_karpuzkntrl = 0;
        }

        if (kacan_karpuzkntrl) {
            ui->labelkacankarpuz_sayisi->setText(QString::number(kacan_karpuz));
            kacan_karpuz += 1;
            kacan_karpuzkntrl = 0;
        }
        x=rand()%(veriListesi.count());
        buttonn->setGeometry(veriListesi[x][0].toInt(&ok),veriListesi[x][1].toInt(&ok),60,60);
        buttonn->setIconSize(QSize(50, 50));
        buttonn->setIcon(QIcon(":/images/images/1.png"));

        btns.push_back(buttonn);
        buttonn->show();
    }

    int listeuzunluk = btns.size();
    for (int i = 0; i < listeuzunluk; ++i) {
        if (btns[i]->tikladinmi && btns[i]->isVisible()) {
            kesilen_karpuzkntrl = 1;
            btns[i]->setIcon(QIcon(":/images/images/2.png"));
            silinecek.append(i);
        }
        else {
            btns[i]->setGeometry(btns[i]->x(), btns[i]->y() + 6, btns[i]->width(), btns[i]->height());
        }
    }

    for (int i = 0; i < listeuzunluk; ++i) {
        if (btns[i]->y() >= 950 && btns[i]->kacirdinmi) {
            kacan_karpuzkntrl = 1;
            btns[i]->kacirdinmi = false;
        }
    }

    kontrol += 1;
}


void Dialog::zamanlayıcı()
{
    int maks=0;
    ui->labelsure_deger->setText(QString::number(suresayac));
    suresayac -= 1;

    if(suresayac<0)
    {

        QFile dosya("/home/esen/Masaüstü/19010011047_odev_1/skorlar.txt");

        if (dosya.open(QIODevice::Append | QIODevice::Text)) { // Dosyayı aç ve sonuna ekleme yap


            QTextStream yazici(&dosya);
            yazici << kesilen_karpuz-1 << Qt::endl; // Skoru dosyaya yazdır

            dosya.close(); // Dosyayı kapat
            qDebug() << "Skor dosyaya başarıyla yazıldı.";
        } else {
            qDebug() << "Dosya açılamadı.";
        }



        if (!dosya.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Dosya açılamadı.";
        }

        QTextStream okuyucu(&dosya);
        while (!okuyucu.atEnd())
        {
            QString satir = okuyucu.readLine();
            if(maks <satir.toInt())
            {
                maks=satir.toInt();
            }


        }
        qDebug() << maks;
        if (maks < kesilen_karpuz) { // kazandıgı senaryo
            QMessageBox::information(this,"Bilgi!","Oyun Bitti! Tebrikler! Maksimum Skor Sizde!\nKesilen Karpuz Sayisi: "
                                                         + QString::number(kesilen_karpuz-1) +"\nKaçırılan Karpuz Sayisi: "+QString::number(kacan_karpuz-1 )
                                                         + "\nMaximum Skor: "+ QString::number(maks));
        } else { // geçilemeyen senaryo
            QMessageBox::information(this,"Bilgi!","Oyun Bitti! Maksimum Skoru Geçemediniz!\nKesilen Karpuz Sayisi: "
                                                         + QString::number(kesilen_karpuz-1) +"\nKaçırılan Karpuz Sayisi: "+QString::number(kacan_karpuz-1 )
                                                         + "\nMaximum Skor: "+ QString::number(maks));
        }

        // oyun sonlanması
        QMessageBox msgBox;
        msgBox.setText("Uygulamayı kapatmak istiyor musunuz?");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int cvp = msgBox.exec();
        if (cvp == QMessageBox::Ok) {
            qApp->quit(); // Uygulamayı kapat
        }
    }

}

void Dialog::kesilenKarpuz()
{
    ui->labelkesilenkarpuz_sayisi->setText(QString::number(kesilen_karpuz));
    kesilen_karpuz += 1;
}


