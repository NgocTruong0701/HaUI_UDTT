#include <iostream>
#include <cmath>

using namespace std;

void input(int *&c, int &n, int &s){
	do{
		cout << "Nhap so luong menh gia tien: ";
		cin >> n;
		if(n < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 1);
	c = new int[n];
	for(int i=0; i<n; i++){
		int j;
		do{
			cout << "Nhap menh gia tien thu " << i+1 << ": ";
			cin >> c[i];
			if(c[i] < 1)
				cout << "Nhap sai. Nhap lai!\n";
			else{
				for(j=0; j<i && c[j]!=c[i]; j++);
				if(j < i)
					cout << "Da co menh gia tien nay. Nhap lai!\n";
			}
		} while(j < i || c[i] < 1);
	}
	do{
		cout << "Nhap so tien can doi: ";
		cin >> s;
		if(s < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(s < 1);
}

void coinChanging(int *c, int n, int s){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(c[i]<c[j])
				swap(c[i],c[j]);
	int *a = new int[n];
	for(int i=0; i<n; i++)
		a[i] = 0;
	for(int i=0; i<n; i++)
		if(s >= c[i]){
			a[i] = s/c[i];
			s = s%c[i];
		}
	cout << "Can dung: ";
	int i;
	for(i=0; i<n; i++)
		if(a[i] != 0){
			cout << a[i] << " dong " << c[i];
			break;
		}
	for(i++; i<n; i++)
		if(a[i] != 0)
			cout << ", " << a[i] << " dong " << c[i];
}

int main(){
	int *c, n, s;
	input(c,n,s);
	coinChanging(c,n,s);
}
