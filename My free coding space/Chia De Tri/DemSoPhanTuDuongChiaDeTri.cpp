#include <iostream>

using namespace std;

//Ham nhap mang
void input(float *&a, int &n){
	do{
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
		if(n <= 1)
			cout << "\nNhap sai. Nhap lai!\n";
	} while(n <= 1);
	a = new float[n];
	for(int i = 0; i < n; i++){
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

//Ham tra ve so phan tu duong trong mang
int count(float *a, int l, int r){
	if(l == r){
		if(a[l] > 0)
			return 1;
		else
			return 0;
	}
	else{
		int m = (l + r) / 2;
		return count(a,l,m) + count(a,m+1,r);
	}
}

int main(){
	float *a;
	int n;
	input(a,n);
	cout << "So phan tu duong trong mang la: " << count(a,0,n-1);
}
