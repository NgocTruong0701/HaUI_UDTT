#include <iostream>

using namespace std;

struct Package{
	int i, a;
	float m, k;
};

void input(float &s, Package *&p, int &n){
	do{
		cout << "Nhap so luong kien hang: ";
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
			cout << "Nhap khoi luong cua kien hang (> 0): ";
			cin >> p[i].m;
			if(p[i].m <= 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(p[i].m <= 0);
		do{
			cout << "Nhap kich thuoc cua kien hang (> 0): ";
			cin >> p[i].k;
			if(p[i].k <= 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(p[i].k <= 0);
	}
	do{
		cout << "Nhap kich thuoc thung xe cua John: ";
		cin >> s;
		if(s <= 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(s <= 0);
}

void arrange(float s, Package *p, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(p[i].m/p[i].k < p[j].m/p[j].k)
				swap(p[i],p[j]);
	int c = 0;
	float b = 0;
	for(int i=0; i<n; i++)
		if(s >= p[i].k){
			s -= p[i].k;
			p[i].a = 1;
			b += p[i].m;
			c ++;
		}
	cout << "Xep duoc " << c << " kien hang gom: ";
	int i;
	for(i=0; i<n; i++)
		if(p[i].a == 1){
			cout << "kien hang " << p[i].i;
			break;
		}
	for(i++; i<n; i++)
		if(p[i].a == 1)
			cout << ", kien hang " << p[i].i;
	cout << "\nVoi khoi luong la: " << b << endl;
}

int main(){
	Package *p;
	float s;
	int n;
	input(s,p,n);
	arrange(s,p,n);
}
