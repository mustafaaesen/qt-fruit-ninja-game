#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMouseEvent>
#include <QIcon>
#include <QSize>
#include <QPixmap>
#include <QTimer>
#include <buttons.h>
#include <QMessageBox>
#include <QFile>
#include <QCoreApplication>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void karpuzOlustur();
    void zamanlayıcı();
    void kesilenKarpuz();

private:
    Ui::Dialog *ui;

    QList<buttons*> btns;
    QList<int> silinecek;
};
#endif // DIALOG_H
