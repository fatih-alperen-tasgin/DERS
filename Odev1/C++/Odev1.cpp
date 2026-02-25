/*****************************************************************************
**                          SAKARYA UNIVERSITESI                            **
**               BILGISAYAR VE BILISIM BILIMLERI FAKULTESI                  **
**                    BILGISAYAR MUHENDISLIGI BOLUMU                        **
**                      PROGRAMLAMAYA GIRIS DERSI                           **
**                                                                          **
**                ODEV NUMARASI: 1                                          **
**                OGRENCI ADI: FATIH ALPEREN TASGIN                         **
**                OGRENCI NUMARASI: B241210079                              **
**                DERS GRUBU: 1. OGRETIM B GRUBU                            **
*****************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Urun yapisini tanimliyoruz
struct Urun {
    string adi;
    int stokMiktari;
    float alisFiyati;
    float kdvOrani;
    float satisFiyati;
    int satilanMiktar;  
    float kar;  
    
};

// Kullanilacak fonksiyonlar
void SatisFiyatlariniHesapla(Urun urunler[], int urunSayisi);
void SatilanStoklariHesapla(Urun urunler[], int urunSayisi);
void YeniStoklariHesapla(Urun urunler[], int urunSayisi);
void AylikKarHesapla(Urun urunler[], int urunSayisi, float giderler, float& aylikKar, float& toplamKar);
void IstatistikYazdir(Urun urunler[], int urunSayisi, int ay);
void YilSonuIstatistikYazdir(Urun urunler[], int urunSayisi);
	
	float RastgeleSatisFiyati(float alisFiyati);
	int RastgeleSatilanStok(int mevcutStok);
	int HesaplaYeniStok(int kalanStok, int satilanStok);

int main() {
    setlocale(LC_ALL,"Turkish");
    srand(time(0)); 

    // Urun bilgilerini tutan dizi
    const int urunSayisi = 15;
    Urun urunler[urunSayisi] = {
        {"Mouse", 20, 50.00, 20.0, 0, 0, 0},
        {"Mikrofon", 15, 100.0, 18.0, 0, 0, 0},
        {"Cep Telefonu", 10, 2000.0, 18.0, 0, 0, 0},
        {"Masaustu Bilgisayar", 8, 10000.0, 18.0, 0, 0, 0},
        {"Laptop", 5, 5000.0, 18.0, 0, 0, 0},
        {"Kulaklik",25,50.00,18.0,0,0,0},
        {"Sarj Aleti",20,200.0,18.0,0,0,0},
        {"Telefon Kilifi",10,20.0,18.0,0,0,0},
        {"Klavye",10,150.0,18.0,0,0,0},
        {"Oyun Konsolu",5,100.0,18.0,0,0,0},
        {"Laptop Sogutucu",5,200.0,18.0,0,0,0},
        {"Tablet",10,1000.0,18.0,0,0,0},
        {"Telefon Tutacagi",5,25.0,18.0,0,0,0},
        {"Laptop Cantasi",5,500.0,18.0,0,0,0},
        {"Kamera",8,400.0,18.0,0,0,0}
        
        
        
    };

    float genelGiderler = 5000.0f; // Kira, elektrik vb. masraflar
    float toplamKar = 0;

    cout << fixed << setprecision(2);
    cout << "\n=============================================" << endl;
    cout << "      MAGAZA AYLIK / YILLIK RAPORLAMA" << endl;
    cout << "=============================================\n" << endl;

    for (int ay = 1; ay <= 12; ay++) {
        cout << "\n---------------------------------------------" << endl;
        cout << "                 " << ay << ". AY RAPORU" << endl;
        cout << "---------------------------------------------" << endl;

        // Islev cagrilari
        SatisFiyatlariniHesapla(urunler, urunSayisi);
        SatilanStoklariHesapla(urunler, urunSayisi);
        YeniStoklariHesapla(urunler, urunSayisi);

        float aylikKar = 0;
        AylikKarHesapla(urunler, urunSayisi, genelGiderler, aylikKar, toplamKar);

        // Her ay icin istatistikleri yazdir
        IstatistikYazdir(urunler, urunSayisi, ay);
    }

    // Yil sonu istatistiklerini yazdir
    cout << "\n=============================================" << endl;
    cout << "           YIL SONU ISTATISTIKLERI" << endl;
    cout << "=============================================" << endl;
    YilSonuIstatistikYazdir(urunler, urunSayisi);

    cout << left << setw(24) << "Yil Sonu Toplam Kar" << ": " << toplamKar << " TL" << endl;

    cout << "Cikmak icin Enter'a bas...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    return 0;
}

// Rastgele satis fiyati hesaplar
float RastgeleSatisFiyati(float alisFiyati) {
    return alisFiyati + alisFiyati * ((rand() % 21 + 30) / 100.0f);
}

// Satilan stok miktarini rastgele hesaplar
int RastgeleSatilanStok(int mevcutStok) {
    return mevcutStok * ((rand() % 21 + 60) / 100.0f);
}

// Yeni stok hesaplar
int HesaplaYeniStok(int kalanStok, int satilanStok) {
    return 2 * kalanStok + satilanStok * ((rand() % 31 + 70) / 100.0f);
}

// Satis fiyatlarini urunlere uygular
void SatisFiyatlariniHesapla(Urun urunler[], int urunSayisi) {
    for (int i = 0; i < urunSayisi; i++) {
        urunler[i].satisFiyati = RastgeleSatisFiyati(urunler[i].alisFiyati);
    }
}

// Satilan stok miktarlarini hesaplar
void SatilanStoklariHesapla(Urun urunler[], int urunSayisi) {
    for (int i = 0; i < urunSayisi; i++) {
        urunler[i].satilanMiktar = RastgeleSatilanStok(urunler[i].stokMiktari);
        urunler[i].stokMiktari -= urunler[i].satilanMiktar; // Satilan miktar stoktan dusuluyor
        urunler[i].kar = urunler[i].satilanMiktar * urunler[i].satisFiyati - urunler[i].satilanMiktar * urunler[i].alisFiyati;
    }
}

// Yeni stok miktarlarini hesaplar
void YeniStoklariHesapla(Urun urunler[], int urunSayisi) {
    for (int i = 0; i < urunSayisi; i++) {
        urunler[i].stokMiktari = HesaplaYeniStok(urunler[i].stokMiktari, urunler[i].satilanMiktar);
    }
}

// Aylik ve toplam kari hesaplar
void AylikKarHesapla(Urun urunler[], int urunSayisi, float giderler, float& aylikKar, float& toplamKar) {
    float toplamGelir = 0;
    for (int i = 0; i < urunSayisi; i++) {
        toplamGelir += urunler[i].satisFiyati * urunler[i].satilanMiktar;
    }
    aylikKar = toplamGelir - giderler;
    toplamKar += aylikKar;
    cout << left << setw(24) << "Aylik Kar" << ": " << aylikKar << " TL" << endl;
}

// Her ay icin istatistikleri yazdiran fonksiyon
void IstatistikYazdir(Urun urunler[], int urunSayisi, int ay) {
    Urun enCokSatan, enAzSatan, enCokKarEden, enAzKarEden;

    // Baslangicta ilk urunu al
    enCokSatan = enAzSatan = enCokKarEden = enAzKarEden = urunler[0];

    for (int i = 0; i < urunSayisi; i++) {
        // En cok satilan urunu bul
        if (urunler[i].satilanMiktar > enCokSatan.satilanMiktar) {
            enCokSatan = urunler[i];
        }
        // En az satilan urunu bul
        if (urunler[i].satilanMiktar < enAzSatan.satilanMiktar) {
            enAzSatan = urunler[i];
        }
        // En cok kar getiren urunu bul
        if (urunler[i].kar > enCokKarEden.kar) {
            enCokKarEden = urunler[i];
        }
        // En az kar getiren urunu bul
        if (urunler[i].kar < enAzKarEden.kar) {
            enAzKarEden = urunler[i];
        }
    }

        cout << left << setw(24) << "En Cok Satilan Urun" << ": " << enCokSatan.adi
            << " (Satilan Miktar: " << enCokSatan.satilanMiktar << ")" << endl;
        cout << left << setw(24) << "En Az Satilan Urun" << ": " << enAzSatan.adi
            << " (Satilan Miktar: " << enAzSatan.satilanMiktar << ")" << endl;
        cout << left << setw(24) << "En Cok Kar Getiren" << ": " << enCokKarEden.adi
            << " (Kar: " << enCokKarEden.kar << " TL)" << endl;
        cout << left << setw(24) << "En Az Kar Getiren" << ": " << enAzKarEden.adi
            << " (Kar: " << enAzKarEden.kar << " TL)" << endl;
}

// Yil sonu istatistiklerini yazdiran fonksiyon
void YilSonuIstatistikYazdir(Urun urunler[], int urunSayisi) {
    Urun enCokSatan, enAzSatan, enCokKarEden, enAzKarEden;

    // Baslangicta ilk urunu al
    enCokSatan = enAzSatan = enCokKarEden = enAzKarEden = urunler[0];

    for (int i = 0; i < urunSayisi; i++) {
        // En cok satilan urunu bul
        if (urunler[i].satilanMiktar > enCokSatan.satilanMiktar) {
            enCokSatan = urunler[i];
        }
        // En az satilan urunu bul
        if (urunler[i].satilanMiktar < enAzSatan.satilanMiktar) {
            enAzSatan = urunler[i];
        }
        // En cok kar getiren urunu bul
        if (urunler[i].kar > enCokKarEden.kar) {
            enCokKarEden = urunler[i];
        }
        // En az kar getiren urunu bul
        if (urunler[i].kar < enAzKarEden.kar) {
            enAzKarEden = urunler[i];
        }
    }
	
        cout << left << setw(24) << "En Cok Satilan Urun" << ": " << enCokSatan.adi
            << " (Satilan Miktar: " << enCokSatan.satilanMiktar << ")" << endl;
        cout << left << setw(24) << "En Az Satilan Urun" << ": " << enAzSatan.adi
            << " (Satilan Miktar: " << enAzSatan.satilanMiktar << ")" << endl;
        cout << left << setw(24) << "En Cok Kar Getiren" << ": " << enCokKarEden.adi
            << " (Kar: " << enCokKarEden.kar << " TL)" << endl;
        cout << left << setw(24) << "En Az Kar Getiren" << ": " << enAzKarEden.adi
            << " (Kar: " << enAzKarEden.kar << " TL)" << endl;        
}


