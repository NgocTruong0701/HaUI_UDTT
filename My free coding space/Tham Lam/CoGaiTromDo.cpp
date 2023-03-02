#include <iostream>

using namespace std;

struct Package{
	int i, a;
	float m, s;
};

void input(float &k, Package *&p, int &n){
	do{
		cout << "Nhap so luong goi hang: ";
		cin >> n;
		if(n < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 1);
	p = new Package[n];
	for(int i=0; i<n; i++){
		p[i].i = i + 1;
		p[i].a = 0;
		cout << "KIEN HANG THU " << i+1 << endl;
		do{
			cout << "Nhap khoi luong cua goi hang (> 0): ";
			cin >> p[i].m;
			if(p[i].m <= 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(p[i].m <= 0);
		do{
			cout << "Nhap kich thuoc cua goi hang (> 0): ";
			cin >> p[i].s;
			if(p[i].s <= 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(p[i].s <= 0);
	}
	do{
		cout << "Nhap kich thuoc balo: ";
		cin >> k;
		if(k <= 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(k <= 0);
}

void arrange(float k, Package *p, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(p[i].m/p[i].s > p[j].m/p[j].s)
				swap(p[i],p[j]);
	int c = 0;
	float b = 0;
	for(int i=0; i<n; i++)
		if(k >= p[i].s){
			k -= p[i].s;
			p[i].a = 1;
			b += p[i].m;
			c ++;
		}
	cout << "Xep duoc " << c << " goi hang gom: ";
	int i;
	for(i=0; i<n; i++)
		if(p[i].a == 1){
			cout << "goi hang " << p[i].i;
			break;
		}
	for(i++; i<n; i++)
		if(p[i].a == 1)
			cout << ", goi hang " << p[i].i;
	cout << "\nVoi khoi luong la: " << b << endl;
}

int main(){
	Package *p;
	float k;
	int n;
	input(k,p,n);
	arrange(k,p,n);
}
