#include <iostream>
#include <iomanip>

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

//Ham hien thi mang
void output(float *a, int n){
	cout << "Mang sau khi sap xep tang dan la:";
	for(int i = 0; i < n; i++){
		cout << setw(6) << a[i];
	}
}

//Ham sap xep tron
void mergeSort(float *a, int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		float *b = new float[r - l + 1];
		for(int i = l; i <= m; i++)
			b[i - l] = a[i];
		for(int i = m + 1; i <= r; i++)
			b[i - l] = a[r + m + 1 - i];
		int j = 0, k = r - l; 
		for(int i = l; i <= r; i++){
			if(b[j] < b[k])
				a[i] = b[j++];
			else
				a[i] = b[k--];
		}
	}
}

int main(){
	float *a;
	int n;
	input(a,n);
	mergeSort(a,0,n-1);
	output(a,n);
}
