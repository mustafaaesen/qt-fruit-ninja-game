# 🍉 Qt Fruit Ninja Oyunu

Bu proje, **C++ ve Qt Framework** kullanılarak geliştirilmiş, Fruit Ninja benzeri basit bir oyun uygulamasıdır. Oyuncu ekranda rastgele çıkan meyveleri keserek puan kazanmaktadır. Arayüz, `Qt Designer` ile oluşturulmuş ve oyun mantığı `C++` ile kodlanmıştır.

## 🎮 Özellikler

- 🎯 Ekrana rastgele çıkan karpuzları tıklayarak kesme
- 🧠 Skor takibi ve dinamik skor güncelleme
- 💾 Skorlar `skorlar.txt` dosyasında saklanır
- 📁 `konumlar.txt` dosyası üzerinden rastgele koordinat seçimi
- 🖼️ Resource dosyası (`resource.qrc`) ile görsel içerik yönetimi

## 🛠️ Kullanılan Teknolojiler

- **Qt Framework (5.x veya 6.x)**
- **C++**
- **Qt Designer (UI dosyaları)**
- `QPushButton`, `QTimer`, `QMessageBox` gibi Qt bileşenleri

## 🚀 Kurulum

### Qt Creator ile açmak için:

1. Qt Creator’u açın
2. `Fruit_Ninja_Game` klasöründeki `.pro` dosyasını içe aktarın
3. Gerekirse `build/` klasörünü silin ve yeniden derleyin
4. Projeyi çalıştırın!

## 📁 Dosya Yapısı

Fruit_Ninja_Game/
│
├── images/ → Oyun içi görseller
├── buttons.cpp/.h → Oyun içi buton mantığı
├── dialog.cpp/.ui → Ana arayüz tasarımı
├── skorlar.txt → Skor kayıt dosyası
├── konumlar.txt → Koordinat verileri
├── main.cpp → Uygulama girişi
├── resource.qrc → Qt kaynak dosyası
├── *.pro → Qt proje yapılandırması


## 📝 Notlar

- Oyun arayüzü sade ve öğretici amaçla tasarlanmıştır.
- `build/`, `.user` gibi derleme dosyaları `.gitignore` ile hariç tutulmuştur.
- Skorlar metin dosyasında tutulmaktadır. İleride veritabanı kullanılabilir.





