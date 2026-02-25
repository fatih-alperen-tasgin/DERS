/****************************************************************************
**                            SAKARYA UNIVERSITESI                         **
**                     BILGISAYAR VE BILISIM BILIMLERI FAKULTESI           **
**                          BILGISAYAR MUHENDISLIGI BOLUMU                 **
**                            PROGRAMLAMAYA GIRIS DERSI                    **
**                                                                         **
**                     ODEV NUMARASI : 2                                   **
**                     ODEV KONUSU : TAVUK CIFTLIGI SIMULASYONU            **
**                     OGRENCI ADI : FATIH ALPEREN TASGIN                  **
**                     OGRENCI NUMARASI : B241210079                       **
**                     DERS GRUBU : 1. OGRETIM B GRUBU                     **
****************************************************************************/

#include <iostream>
#include <iomanip> // setw, setprecision
#include <cstdlib> // rand, srand
#include <ctime>   // time

using namespace std;

class Tavuk {
private:
    int yumurtlamaDurumu; // Kac gun yumurtlamadigini takip eder
    int toplamYumurta;    // Toplam yumurta sayisi
    int gunSayisi;        // Ciftlikte gecirdigi toplam gun sayisi

public:
    Tavuk() {
        yumurtlamaDurumu = 0;
        toplamYumurta = 0;
        gunSayisi = 0;
    }

    int yumurtla() {
        if (gunSayisi < 3) {
            return 0; // Ilk 3 gun yumurtlamaz
        }
        int yumurta = rand() % 3; // 0, 1 veya 2 yumurta
        toplamYumurta += yumurta;
        yumurtlamaDurumu = (yumurta == 0) ? yumurtlamaDurumu + 1 : 0;
        return yumurta;
    }

    int yemYe() {
        return 100 + (rand() % 21); // 100-120 gram yem tuketimi
    }

    bool kesimKontrol() {
        return (yumurtlamaDurumu >= 3 || toplamYumurta >= 100);
    }

    void gunArtir() {
        gunSayisi++;
    }

    void sifirla() {
        yumurtlamaDurumu = 0;
        toplamYumurta = 0;
        gunSayisi = 0;
    }
};

class Ciftlik {
private:
    int tavukSayisi;
    double kalanPara;
    double yemKilogramFiyati;
    double yumurtaFiyati;
    double tavukAlimFiyati;
    double kalanYem;
    Tavuk* tavuklar; // Tavuk dizisi

public:
    Ciftlik(double sermaye, int tavukSayisi, double yemFiyati, double yumurtaFiyati, double tavukFiyati)
        : kalanPara(sermaye), tavukSayisi(tavukSayisi), yemKilogramFiyati(yemFiyati),
          yumurtaFiyati(yumurtaFiyati), tavukAlimFiyati(tavukFiyati), kalanYem(700) {
        tavuklar = new Tavuk[tavukSayisi]; // Tavuk dizisini dinamik olarak olustur
        kalanPara -= tavukSayisi * tavukAlimFiyati; // Tavuklarin alim gideri
        kalanPara -= 700 * yemKilogramFiyati;      // 700 kilogram yem gideri
    }

    ~Ciftlik() {
        delete[] tavuklar; // Dinamik bellek temizligi
    }

    void simulasyonYap(int gunSayisi) {
        cout << left << setw(5) << "Gun"
             << setw(15) << "Yem Tuketimi"
             << setw(10) << "Yumurta"
             << setw(15) << "Kesilen Tavuk"
             << setw(15) << "Gunluk Gelir"
             << setw(15) << "Gunluk Gider"
             << setw(12) << "Kalan Yem"
             << setw(12) << "Kalan Para" << endl;

        cout << setfill('-') << setw(100) << "" << setfill(' ') << endl;

        for (int gun = 1; gun <= gunSayisi; gun++) {
            int toplamYumurta = 0;
            int kesilenTavukSayisi = 0;
            double yemTuketimi = 0;
            double gunlukGelir = 0;
            double gunlukGider = 0;

            for (int i = 0; i < tavukSayisi; i++) {
                yemTuketimi += tavuklar[i].yemYe();
                toplamYumurta += tavuklar[i].yumurtla();

                if (tavuklar[i].kesimKontrol()) {
                    kesilenTavukSayisi++;
                    gunlukGelir += tavukAlimFiyati / 2; // Kesimden gelir
                    gunlukGider += tavukAlimFiyati;    // Yeni tavuk alimi
                    tavuklar[i].sifirla();             // Yeni tavuk olarak sifirla
                } else {
                    tavuklar[i].gunArtir();
                }
            }

            kalanYem -= yemTuketimi / 1000; // Kilogram cinsinden
            if (kalanYem < 70) {
                kalanYem += 700;
                gunlukGider += 700 * yemKilogramFiyati;
            }

            gunlukGelir += toplamYumurta * yumurtaFiyati;
            kalanPara += gunlukGelir - gunlukGider;

            cout << left << setw(5) << gun
                 << setw(15) << fixed << setprecision(2) << yemTuketimi
                 << setw(10) << toplamYumurta
                 << setw(15) << kesilenTavukSayisi
                 << setw(15) << gunlukGelir
                 << setw(15) << gunlukGider
                 << setw(12) << kalanYem
                 << setw(12) << kalanPara << endl;

            if (kalanPara < 0) {
                cout << "\nIflas ettiniz..." << endl;
                return;
            }
        }
    }
};

int main() {
    srand(time(0)); // Rastgele sayilar icin
    setlocale(LC_ALL,"Turkish");

    double sermaye;
    int tavukSayisi;
    double yemFiyati, yumurtaFiyati, tavukFiyati;
    int gunSayisi;

    cout << "Baslangic sermayesi: ";
    cin >> sermaye;
    while (sermaye <= 0) {
        cout << "Gecerli bir sermaye girin (pozitif bir sayi): ";
        cin >> sermaye;
    }

    cout << "Ciftlikte kac tavuk olacak (en fazla 500): ";
    cin >> tavukSayisi;
    while (tavukSayisi <= 0 || tavukSayisi > 500) {
        cout << "Lutfen 1 ile 500 arasinda bir tavuk sayisi girin: ";
        cin >> tavukSayisi;
    }

    cout << "Tavuk yeminin kilogram fiyati: ";
    cin >> yemFiyati;
    while (yemFiyati <= 0) {
        cout << "Gecerli bir yem kilogram fiyati girin (pozitif bir sayi): ";
        cin >> yemFiyati;
    }

    cout << "Yumurtanin satis fiyati: ";
    cin >> yumurtaFiyati;
    while (yumurtaFiyati <= 0) {
        cout << "Gecerli bir yumurta fiyati girin (pozitif bir sayi): ";
        cin >> yumurtaFiyati;
    }

    cout << "Tavuk alim fiyati: ";
    cin >> tavukFiyati;
    while (tavukFiyati <= 0) {
        cout << "Gecerli bir tavuk alim fiyati girin (pozitif bir sayi): ";
        cin >> tavukFiyati;
    }

    cout << "Simulasyon yapilacak gun sayisi: ";
    cin >> gunSayisi;
    while (gunSayisi <= 0) {
        cout << "Gecerli bir gun sayisi girin (pozitif bir sayi): ";
        cin >> gunSayisi;
    }

    Ciftlik ciftlik(sermaye, tavukSayisi, yemFiyati, yumurtaFiyati, tavukFiyati);
    ciftlik.simulasyonYap(gunSayisi);

    return 0;
}