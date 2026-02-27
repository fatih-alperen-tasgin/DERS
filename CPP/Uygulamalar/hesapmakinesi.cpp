#include<iostream>

using namespace std;

int main() { 

 	char islem;
    double sayi1, sayi2;

    cout << "Bir sayi girin: ";
    cin >> sayi1 ;
    
    cout << "Bir islem secin (+, -, *, /): ";
    cin >> islem;

	cout << "Bir sayi girin: " ;
	cin >> sayi2  ;
	
    switch (islem) 
	{
        case '+':
            cout << sayi1 << " + " << sayi2 << " = " << sayi1 + sayi2 << endl;
            break;
            
        case '-':
            cout << sayi1 << " - " << sayi2 << " = " << sayi1 - sayi2 << endl;
            break;
            
        case '*':
            cout << sayi1 << " * " << sayi2 << " = " << sayi1 * sayi2 << endl;
            break;
            
        case '/':
            if ( sayi2 != 0)
                cout << sayi1 << " / " << sayi2 << " = " << sayi1 / sayi2 << endl;
            else
                cout << "Hata: Sifira bolme!" << endl;
            break;
             
        default:
            cout << "Gecersiz islem!" << endl;
            break;
    }
    
	return 0 ;
}
	
