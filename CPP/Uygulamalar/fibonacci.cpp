#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Kac elemanli Fibonacci dizisi istiyorsunuz? ";
    if (!(cin >> n)) {
        cout << "Gecersiz giris, lutfen tam sayi giriniz" << endl;
        return 1;
    }

    if (n <= 0) {
        cout << "Lutfen 1 ile 100 arasinda bir deger giriniz" << endl;
        return 1;
    }

    if (n > 100) {
        cout << "En fazla 100 eleman girebilirsiniz" << endl;
        return 1;
    }

    int fibonacci[100]; // 100 elemanli bir dizi tanimlanmistir, ihtiyaca gore boyutunu arttirabilirsiniz
    fibonacci[0] = 1;
    if (n > 1) {
        fibonacci[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    cout << "Fibonacci Dizisi: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci[i] << " ";
    }
    cout << endl;

    return 0;
}

