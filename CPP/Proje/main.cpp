/****************************************************************************
**                SAKARYA UNIVERSITESI                                     **
**                BILGISAYAR VE BILISIM BOLUMLERI FAKULTESI                **
**                BILGISAYAR MUHENDISLIGI BOLUMU                           **
**                NESNEYE DAYALI PROGRAMLAMA DERSI                         **
**                2024-2025 GUZ DONEMI                                     **
**                                                                         **
**                ODEV NUMARASI        :   1.PROJE                         **
**                OGRENCI ADI          :   FATIH ALPEREN TASKIN            **
**                OGRENCI NUMARASI     :   B241210079                      **
**                DERSIN ALINDIGI GRUP :   1.OGRETIM B GRUBU               **
****************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Mekan {
	protected :
		string mekanAdi;
		bool durum ;
	public:
    Mekan(string ad) : mekanAdi(ad), durum(true) {}
    
    virtual void bilgileriYaz() {
        cout << "Mekan Adi: " << mekanAdi << ", Durum: " << (durum ? "Aktif" : "Pasif") << endl;
    }

    string getMekanAdi() {
        return mekanAdi;
    }

    void setDurum(bool d) {
        durum = d;
    }

    bool getDurum() {
        return durum;
    }
};

class Daire : public Mekan {
private:
    int odaSayisi;

public:
    Daire(string isim, int alan, int odaSayisi)
        : Mekan(isim), odaSayisi(odaSayisi) {}

    void bilgileriYaz() override {
        Mekan::bilgileriYaz();
        cout << "Oda Sayisi: " << odaSayisi << endl;
    }
};

class Fitness : public Mekan {
private:
    bool sporEkipmanlari;

public:
    Fitness(std::string isim, int alan, bool sporEkipmanlari)
        : Mekan(isim), sporEkipmanlari(sporEkipmanlari) {}

    void bilgileriYaz() override {
        Mekan::bilgileriYaz();
        cout << "Spor Ekipmanlari: " << (sporEkipmanlari ? "Mevcut" : "Yok") << endl;
    }
};

class Havuz : public Mekan {
private:
    bool isitmaSistemi;

public:
    Havuz(std::string isim, int alan, bool isitmaSistemi)
        : Mekan(isim), isitmaSistemi(isitmaSistemi) {}

    void bilgileriYaz() override {
        Mekan::bilgileriYaz();
        cout << "Isitma Sistemi: " << (isitmaSistemi ? "Var" : "Yok") << endl;
    }
};

void mekanListele() {
    ifstream mekandosya("Mekan.txt", ios::in);
    if (mekandosya.is_open()) {
        cout << "Mekan Listesi:\n";
        string satir;
        while (getline(mekandosya, satir)) {
            cout << satir << endl;
        }
        mekandosya.close();
    } else {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
    }
}

void mekanEkle() {
    ofstream mekandosya("Mekan.txt", ios::app);
    if (mekandosya.is_open()) {
        string bilgi;
        cout << "Eklemek istediginiz bilgiyi girin: ";
        cin.ignore();
        getline(cin, bilgi);
        mekandosya << bilgi << "\n";
        mekandosya.close();
        cout << "Ekleme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
    }
}

void mekanSil() {
    ifstream mekandosya("Mekan.txt", ios::in);
    if (!mekandosya.is_open()) {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<string> satirlar;
    string satir, silinecek;
    cout << "Silmek istediginiz bilgiyi girin: ";
    cin.ignore();
    getline(cin, silinecek);

    while (getline(mekandosya, satir)) {
        if (satir != silinecek) {
            satirlar.push_back(satir);
        }
    }
    mekandosya.close();

    ofstream mekandosyaYaz("Mekan.txt", ios::out |ios::trunc);
    if (mekandosyaYaz.is_open()) {
        for (const auto& satir : satirlar) {
            mekandosyaYaz << satir << "\n";
        }
        mekandosyaYaz.close();
        cout << "Silme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
    }
}

void mekanDuzelt() {
    ifstream dosya("Mekan.txt", ios::in);
    if (!dosya.is_open()) {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<std::string> satirlar;
    string satir, eskiBilgi, yeniBilgi;
    cout << "Duzeltmek istediginiz eski bilgiyi girin: ";
    cin.ignore();
    getline(std::cin, eskiBilgi);
    cout << "Yeni bilgiyi girin: ";
    getline(cin, yeniBilgi);

    while (getline(dosya, satir)) {
        if (satir == eskiBilgi) {
            satirlar.push_back(yeniBilgi);
        } else {
            satirlar.push_back(satir);
        }
    }
    dosya.close();

    ofstream dosyaYaz("Mekan.txt", ios::out|ios::trunc);
    if (dosyaYaz.is_open()) {
        for (const auto& satir : satirlar) {
            dosyaYaz << satir << "\n";
        }
        dosyaYaz.close();
        cout << "Duzeltme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Mekan.txt dosyasi acilamadi!" << endl;
    }
}

void odemeListele() {
    ifstream odemedosya("Odeme.txt", ios::in);
    if (odemedosya.is_open()) {
        cout << "Odeme Listesi:\n";
        string satir;
        while (getline(odemedosya, satir)) {
            cout << satir << endl;
        }
        odemedosya.close();
    } else {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
    }
}

void odemeEkle() {
    ofstream odemedosya("Odeme.txt", ios::app);
    if (odemedosya.is_open()) {
        string bilgi;
        cout << "Eklemek istediginiz bilgiyi girin: ";
        cin.ignore();
        getline(cin, bilgi);
        odemedosya << bilgi << "\n";
        odemedosya.close();
        cout << "Ekleme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
    }
}

void odemeSil() {
    ifstream odemedosya("Odeme.txt", ios::in);
    if (!odemedosya.is_open()) {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<string> satirlar;
    string satir, silinecek;
    cout << "Silmek istediginiz bilgiyi girin: ";
    cin.ignore();
    getline(cin, silinecek);

    while (getline(odemedosya, satir)) {
        if (satir != silinecek) {
            satirlar.push_back(satir);
        }
    }
    odemedosya.close();

    ofstream odemedosyaYaz("Odeme.txt", ios::out |ios::trunc);
    if (odemedosyaYaz.is_open()) {
        for (const auto& satir : satirlar) {
            odemedosyaYaz << satir << "\n";
        }
        odemedosyaYaz.close();
        cout << "Silme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
    }
}

void odemeDuzelt() {
    ifstream dosya("Odeme.txt", ios::in);
    if (!dosya.is_open()) {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<std::string> satirlar;
    string satir, eskiBilgi, yeniBilgi;
    cout << "Duzeltmek istediginiz eski bilgiyi girin: ";
    cin.ignore();
    getline(std::cin, eskiBilgi);
    cout << "Yeni bilgiyi girin: ";
    getline(cin, yeniBilgi);

    while (getline(dosya, satir)) {
        if (satir == eskiBilgi) {
            satirlar.push_back(yeniBilgi);
        } else {
            satirlar.push_back(satir);
        }
    }
    dosya.close();

    ofstream dosyaYaz("Odeme.txt", ios::out|ios::trunc);
    if (dosyaYaz.is_open()) {
        for (const auto& satir : satirlar) {
            dosyaYaz << satir << "\n";
        }
        dosyaYaz.close();
        cout << "Duzeltme islemi basariyla tamamlandi.\n";
    } else {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
    }
}


class Oturan {
	public:
	string ad;
    string soyad;
    string daireNo;
    string telefonNo;

   public:
        Oturan() : ad(""), soyad(""), daireNo(""), telefonNo("") {}

        Oturan(const string& ad, const string& soyad, const string& daireNo, const string& telefonNo)
            : ad(ad), soyad(soyad), daireNo(daireNo), telefonNo(telefonNo) {}

        string getAd() const { return ad; }
        string getSoyad() const { return soyad; }
        string getDaireNo() const { return daireNo; }
        string getTelefonNo() const { return telefonNo; }

        void setAd(const string& ad) { this->ad = ad; }
        void setSoyad(const string& soyad) { this->soyad = soyad; }
        void setDaireNo(const string& daireNo) { this->daireNo = daireNo; }
        void setTelefonNo(const string& telefonNo) { this->telefonNo = telefonNo; }

        string toString() const {
            return ad + " " + soyad + " " + daireNo + " " + telefonNo;
        }

        static Oturan fromString(const string& str) {
            stringstream ss(str);
            Oturan o;
            ss >> o.ad >> o.soyad >> o.daireNo >> o.telefonNo;
            return o;
        }
	
};

void oturanEkle() {
    ofstream dosya("Data.txt", ios::app);
    if (!dosya.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    Oturan yeniOturana;
    cout << "Ad: ";
    cin >> yeniOturana.ad;
    cout << "Soyad: ";
    cin >> yeniOturana.soyad;
    cout << "Daire No: ";
    cin >> yeniOturana.daireNo;
    cout << "Telefon No: ";
    cin >> yeniOturana.telefonNo;

    dosya << yeniOturana.toString() << endl;
    dosya.close();
    cout << "Oturan ekleme islemi basariyla tamamlandi." << endl;
}

// Oturana ait bilgiyi dosyadan silen fonksiyon
void oturanSil() {
    ifstream dosya("Data.txt", ios::in);
    if (!dosya.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<Oturan> oturanListesi;
    string satir;
    string silinecekDaireNo;
    cout << "Silmek istediginiz oturanin daire numarasini girin: ";
    cin >> silinecekDaireNo;

    // Dosyadaki oturanlari okuyoruz
    while (getline(dosya, satir)) {
        Oturan o = Oturan::fromString(satir);
        if (o.daireNo != silinecekDaireNo) {
            oturanListesi.push_back(o); // Silinmeyecek oturanlari listeye ekliyoruz
        }
    }
    dosya.close();

    // Dosyayi tekrar yazma modunda aciyoruz
    ofstream dosyaYaz("Data.txt", ios::out | ios::trunc);
    if (!dosyaYaz.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    // Silinen oturanin disindaki tum oturanlari dosyaya yaziyoruz
    for (const auto& oturan : oturanListesi) {
        dosyaYaz << oturan.toString() << endl;
    }

    dosyaYaz.close();
    cout << "Oturan silme islemi basariyla tamamlandi." << endl;
}

// Oturana ait bilgiyi dosyada duzelten fonksiyon
void oturanDuzelt() {
    ifstream dosya("Data.txt", ios::in);
    if (!dosya.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    vector<Oturan> oturanListesi;
    string satir;
    string eskiDaireNo;
    cout << "Duzeltilmek istenen oturanin daire numarasini girin: ";
    cin >> eskiDaireNo;

    // Dosyadaki oturanlari okuyoruz
    while (getline(dosya, satir)) {
        Oturan o = Oturan::fromString(satir);
        if (o.daireNo == eskiDaireNo) {
            cout << "Yeni Ad: ";
            cin >> o.ad;
            cout << "Yeni Soyad: ";
            cin >> o.soyad;
            cout << "Yeni Telefon No: ";
            cin >> o.telefonNo;
        }
        oturanListesi.push_back(o); // Hem yeni hem eski oturanlari listeye ekliyoruz
    }
    dosya.close();

    // Dosyayi tekrar yazma modunda aciyoruz
    ofstream dosyaYaz("Data.txt", ios::out | ios::trunc);
    if (!dosyaYaz.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    // Duzeltilmis oturanlari dosyaya yaziyoruz
    for (const auto& oturan : oturanListesi) {
        dosyaYaz << oturan.toString() << endl;
    }

    dosyaYaz.close();
    cout << "Oturan duzeltme islemi basariyla tamamlandi." << endl;
}

// Dosyadaki tum oturanlari listeleyen fonksiyon
void oturanListele() {
    ifstream dosya("Data.txt", ios::in);
    if (!dosya.is_open()) {
        cout << "Data.txt dosyasi acilamadi!" << endl;
        return;
    }

    string satir;
    cout << "Oturanlarin Listesi:\n";
    while (getline(dosya, satir)) {
        cout << satir << endl;
    }
    dosya.close();
}

   



int main() {
	setlocale(LC_ALL,"Turkish");
	ofstream mekandosya("Mekan.txt");

    if (mekandosya.is_open()) {
        mekandosya << "Daireler:\n";
        mekandosya << "1. Daire - 2+1, 100m2 \n";
        mekandosya << "2. Daire - 3+1, 120m2 \n";
        mekandosya << "3. Daire - 1+1, 70m2 \n\n";
        
        mekandosya << "Spor Salonu:\n";
        mekandosya << "Acilis saati: 06:00 - 22:00\n";
        mekandosya << "Ekipmanlar: Kosu bandi, agirliklar, bisiklet ...\n";
        mekandosya << "Haftalik aktivite: Yoga, pilates ...\n\n";
        
        mekandosya << "Havuzlar:\n";
        mekandosya << "1. Kapali Havuz - Derinlik: 4m, 10x20m, 08:00 - 20:00 arasi acik\n";
        mekandosya << "2. Acik Havuz - Derinlik: 4m, 15x30m, 09:00 - 18:00 arasi acik\n";
        mekandosya << "3. Cocuk Havuzu - Derinlik: 1m, 10:00 - 17:00 arasi acik \n\n";
    
        mekandosya.close();

        cout << "Mekan.txt dosyasi olusturuldu, veriler kaydedildi." << endl;
    } else {
        cout << "Ilgili dosya acilamadi!" << endl;
    }
    
	 
	ofstream datadosya("Data.txt");
	 
    if (datadosya.is_open()) {
	
	    datadosya << "Oturanlar:\n";
	    
	    datadosya << "Adi: Ahmet Yilmaz, Daire Numarasi: 1  \n";
        datadosya << "Adi: Elif Demir, Daire Numarasi: 2  \n";
        datadosya << "Adi: Mehmet Kaya, Daire Numarasi: 3  \n\n";
        
        datadosya.close();

        cout << "Data.txt dosyasi olusturuldu, veriler kaydedildi." << endl;
    } else {
        cout << "Ilgili dosya acilamadi!" << endl;
    }
    
     ofstream odemeDosya("Odeme.txt");

    if (odemeDosya.is_open()) {
    	
        odemeDosya << "Odemeler:\n";
        odemeDosya << "-----------------------------\n";
        odemeDosya << "Adi: Ahmet Yilmaz\n";
        odemeDosya << "Daire Numarasi: 1\n";
        odemeDosya << "Odeme Miktari: 1500 TL\n";
        odemeDosya << "Odeme Tarihi: 01/12/2024\n";
        odemeDosya << "-----------------------------\n";
        odemeDosya << "Adi: Elif Demir\n";
        odemeDosya << "Daire Numarasi: 2\n";
        odemeDosya << "Odeme Miktari: 1800 TL\n";
        odemeDosya << "Odeme Tarihi: 02/12/2024\n";
        odemeDosya << "-----------------------------\n";
        odemeDosya << "Adi: Mehmet Kaya\n";
        odemeDosya << "Daire Numarasi: 3\n";
        odemeDosya << "Odeme Miktari: 1200 TL\n";
        odemeDosya << "Odeme Tarihi: 03/12/2024\n";
        odemeDosya << "-----------------------------\n\n";
        
        odemeDosya.close();

        cout << "Odeme.txt dosyasi olusturuldu, veriler kaydedildi." << endl;
    } else {
        cout << "Odeme.txt dosyasi acilamadi!" << endl;
    }
    
    ofstream havuzDosya("HavuzKul.txt");

    if (havuzDosya.is_open()) {

        havuzDosya << "Havuz Kullananlar:\n";
        havuzDosya << "-------------------------------\n";
        havuzDosya << "Adi: Ahmet Yilmaz\n";
        havuzDosya << "Daire Numarasi: 1\n";
        havuzDosya << "Kullanim Tarihi: 10/12/2024\n";
        havuzDosya << "Kullanim Suresi: 10 Gun \n";
        havuzDosya << "-------------------------------\n";
        havuzDosya << "Adi: Elif Demir\n";
        havuzDosya << "Daire Numarasi: 2\n";
        havuzDosya << "Kullanim Tarihi: 11/12/2024\n";
        havuzDosya << "Kullanim Suresi: 2 Hafta \n";
        havuzDosya << "-------------------------------\n";
        havuzDosya << "Adi: Mehmet Kaya\n";
        havuzDosya << "Daire Numarasi: 3\n";
        havuzDosya << "Kullanim Tarihi: 12/12/2024\n";
        havuzDosya << "Kullanim Suresi: 3 Gun \n";
        havuzDosya << "-------------------------------\n\n";

        havuzDosya.close();

        cout << "HavuzKul.txt dosyasi olusturuldu, veriler kaydedildi." << endl;
    } else {
        cout << "HavuzKul.txt dosyasi acilamadi!" << endl;
    }

	ofstream sporSalonuDosya("SporSalonu.txt");

    if (sporSalonuDosya.is_open()) {

        sporSalonuDosya << "Spor Salonunu Kullananlar:\n";
        sporSalonuDosya << "-------------------------------\n";
        sporSalonuDosya << "Adi: Ahmet Yilmaz\n";
        sporSalonuDosya << "Daire Numarasi: 1\n";
        sporSalonuDosya << "Kullanim Tarihi: 10/12/2024\n";
        sporSalonuDosya << "Kullanim Suresi: 10 Gun\n";
        sporSalonuDosya << "-------------------------------\n";
        sporSalonuDosya << "Adi: Elif Demir\n";
        sporSalonuDosya << "Daire Numarasi: 2\n";
        sporSalonuDosya << "Kullanim Tarihi: 11/12/2024\n";
        sporSalonuDosya << "Kullanim Suresi: 2 Hafta\n";
        sporSalonuDosya << "-------------------------------\n";
        sporSalonuDosya << "Adi: Mehmet Kaya\n";
        sporSalonuDosya << "Daire Numarasi: 3\n";
        sporSalonuDosya << "Kullanim Tarihi: 12/12/2024\n";
        sporSalonuDosya << "Kullanim Suresi: 3 Gun\n";
        sporSalonuDosya << "-------------------------------\n\n";

        sporSalonuDosya.close();

        cout << "SporSalonu.txt dosyasi olusturuldu, veriler kaydedildi." << endl;
    } else {
        cout << "SporSalonu.txt dosyasi acilamadi!" << endl;
    }
    
    int mekanSecim;

    do {
        cout << "\n--- Mekan Yonetim Menusu ---\n";
        cout << "1. Listele\n";
        cout << "2. Ekle\n";
        cout << "3. Sil\n";
        cout << "4. Duzelt\n";
        cout << "5. Odemeler Menusu\n";
        cout << "6. Cikis\n";
        cout << "Seciminizi yapin: ";
        cin >> mekanSecim;

        switch (mekanSecim) {
            case 1:
                mekanListele();
                break;
            case 2:
                mekanEkle();
                break;
            case 3:
                mekanSil();
                break;
            case 4:
                mekanDuzelt();
                break;
            case 5:
                cout << "Odemeler menusu aciliyor...\n\n";
                break;
            case 6:
	            cout << "Programdan cikiliyor...\n";
            	exit(0);
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyin.\n";
        }
    } while (mekanSecim != 5);
    
    int odemeSecim;

    do {
        cout << "\n--- Odemeler Menusu ---\n";
        cout << "1. Listele\n";
        cout << "2. Ekle\n";
        cout << "3. Sil\n";
        cout << "4. Duzelt\n";
        cout << "5. Oturanlar Menusu\n";
        cout << "6. Cikis\n";
        cout << "Seciminizi yapin: ";
        cin >> odemeSecim;

        switch (odemeSecim) {
            case 1:
                odemeListele();
                break;
            case 2:
                odemeEkle();
                break;
            case 3:
                odemeSil();
                break;
            case 4:
                odemeDuzelt();
                break;
            case 5:
                cout << "Oturanlar menusu aciliyor...\n\n";
                break;
            case 6:
	            cout << "Programdan cikiliyor...\n";
            	exit(0);
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyin.\n";
        }
    } while (odemeSecim != 5);
    
    int oturanSecim;
     
    do {
    	cout << "\n--- Oturanlar Menusu ---\n";
        cout << "1. Listele\n";
        cout << "2. Ekle\n";
        cout << "3. Sil\n";
        cout << "4. Duzelt\n";
        cout << "5. Cikis\n";
        cout << "Seciminizi yapin: ";
        cin >> oturanSecim;

        switch (oturanSecim) {
            case 1:
                oturanListele();
                break;
            case 2:
                oturanEkle();
                break;
            case 3:
                oturanSil();
                break;
            case 4:
                oturanDuzelt();
                break;
            case 5:
                cout << "Programdan cikiliyor...\n";
                break;
            default:
                cout << "Gecersiz secim! Lutfen tekrar deneyin.\n";
        }
    } while (oturanSecim != 5);
        
    
	return 0 ;
}


