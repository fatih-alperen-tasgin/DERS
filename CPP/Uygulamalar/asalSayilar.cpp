#include<iostream>
#include<cmath>
#include<limits>

using namespace std;

bool asalMi(int sayi) {
    if (sayi <= 1) return false;
    if (sayi == 2) return true;
    if (sayi % 2 == 0) return false;
    for (int i = 3; i <= sqrt(sayi); i += 2) {
        if (sayi % i == 0) return false;
    }
    return true;
}
int main() { 
	int secim;
    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1 - Asal sayi kontrol et" << endl;
        cout << "0 - Cikis" << endl;
        cout << "Seciminiz: ";

        if (!(cin >> secim)) {
            cout << "Gecersiz secim, lutfen 0 veya 1 giriniz" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (secim == 0) {
            cout << "Program sonlandi" << endl;
            break;
        } else if (secim == 1) {
            int sayi;
            cout << "Bir sayi giriniz: ";
            if (!(cin >> sayi)) {
                cout << "Gecersiz giris, lutfen tam sayi giriniz" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (asalMi(sayi))
                cout << "Asal" << endl;
            else
                cout << "Asal degil" << endl;
        } else {
            cout << "Gecersiz secim, lutfen 0 veya 1 giriniz" << endl;
        }
    }
        
	return 0 ;
}
	
