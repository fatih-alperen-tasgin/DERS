#include<iostream>

using namespace std;



int main() { 

	int sayi;
	cout << "Faktoriyeli hesaplanacak sayiyi giriniz = ";
	if (!(cin >> sayi)) {
		cout << "Gecersiz giris, lutfen tam sayi giriniz" << endl;
		return 1;
	}

	if (sayi < 0) {
		cout << "Negatif sayilarin faktoriyeli hesaplanamaz" << endl;
		return 1;
	}

	if (sayi > 20) {
		cout << "Tasmayi onlemek icin en fazla 20 girebilirsiniz" << endl;
		return 1;
	}

	unsigned long long faktoriyel=1;
	for( int i=1;i<=sayi;i++)
	{
		faktoriyel*=i;
	}
	
	cout << sayi << "!" << "=" << faktoriyel << endl;





	return 0 ;
}
	
