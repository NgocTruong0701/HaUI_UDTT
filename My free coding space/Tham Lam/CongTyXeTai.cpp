#include <iostream>
#include <cmath>

using namespace std;

void input(float *&c, int &n, float &s){
	do{
		cout << "Nhap so luong xe tai: ";
		cin >> n;
		if(n < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 1);
	c = new float[n];
	for(int i=0; i<n; i++){
		int j;
		do{
			cout << "Nhap tai trong cua xe thu " << i+1 << ": ";
			cin >> c[i];
			if(c[i] <= 0)
				cout << "Nhap sai. Nhap lai!\n";
			else{
				for(j=0; j<i && c[j]!=c[i]; j++);
				if(j < i)
					cout << "Da co xe co tai trong nay. Nhap lai!\n";
			}
		} while(j < i || c[i] <= 0);
	}
	do{
		cout << "Nhap so tan hang can van chuyen: ";
		cin >> s;
		if(s <= 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(s <= 0);
}

void transport(float *c, int n, float s){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(c[i]<c[j])
				swap(c[i],c[j]);
	int i;
	for(i=0; i<n && s>0; i++)
		s -= c[i];
	cout << "So xe tai it nhat can su dung la: " << i << " xe\n";
}

int main(){
	float *c, s;
	int n;
	input(c,n,s);
	transport(c,n,s);
}
