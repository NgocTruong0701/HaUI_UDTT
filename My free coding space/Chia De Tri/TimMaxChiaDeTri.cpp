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

//Ham tim max
float max(float *a, int l, int r){
	if(l == r)
		return a[l];
	else{
		int m = (l + r) / 2;
		if(max(a,l,m) > max(a,m+1,r))
			return max(a,l,m);
		else
			return max(a,m+1,r);
	}
}

int main(){
	float *a;
	int n;
	input(a,n);
	cout << "Gia tri lon nhat trong mang da nhap la: " << max(a,0,n-1);
}
