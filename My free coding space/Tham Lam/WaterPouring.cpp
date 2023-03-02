#include <iostream>
#include <cmath>

using namespace std;

void input(int *&c, int &n, int &s){
	do{
		cout << "Nhap so luong cac chai nuoc: ";
		cin >> n;
		if(n < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 1);
	c = new int[n];
	for(int i=0; i<n; i++){
		int j;
		do{
			cout << "Nhap dung tich cua chai thu " << i+1 << ": ";
			cin >> c[i];
			if(c[i] < 1)
				cout << "Nhap sai. Nhap lai!\n";
			else{
				for(j=0; j<i && c[j]!=c[i]; j++);
				if(j < i)
					cout << "Da co chai co dung tich nay. Nhap lai!\n";
			}
		} while(j < i || c[i] < 1);
	}
	do{
		cout << "Nhap luong nuoc can chiet vao cac chai: ";
		cin >> s;
		if(s < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(s < 1);
}

void waterPouring(int *c, int n, int s){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(c[i]>c[j])
				swap(c[i],c[j]);
	int i;
	for(i=0; i<n && s>=c[i]; i++)
		s -= c[i];
	if(i > 0)
		cout << "Co the do day toi da " << i << " chai\n";
	else
		cout << "Khong the do day chai nao!\n";
}

int main(){
	int *c, n, s;
	input(c,n,s);
	waterPouring(c,n,s);
	for(int i=0; i<n; i++)
		cout << c[i] << " ";
}
