#include <iostream>

using namespace std;
/*
Duyet tu cuoi day len dau day. Thay phan tu a[i] < a[i+1] thi dung lai.
Doi cho phan tu a[i] va phan tu a[n-1].
Dao nguoc vi tri cac phan tu tu a[i+1] den a[n-1]
*/

//Deaclare the configuration (Khai bao giao dien)
int *config;

//Function enterring the size of the configuration
//(Ham nhap vao kich thuoc cua giao dien)
void enter(int &n){
	do{
		cout << "Enter a positive integer number (Nhap vao 1 so nguyen duong): ";
		cin >> n;
		if(n <= 0)
			cout << "Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
	config = new int[n];
	for(int i=0; i<n; i++) //Create the first configuration (Tao giao dien dau tien)
		config[i] = i + 1;
}

//Function displaying a configuration (Ham hien thi 1 giao dien)
void viewConfig(int n){
	cout << config[0];
	for(int i=1; i<n; i++)
		cout << ", " << config[i];
	cout << endl;
}

//Function generating the next configuration based on the current one
//(Ham sinh cau hinh tiep theo tu cau hinh hien tai)
void nextConfig(int n, int i){
	int t;
	for(t=n-1; t>i && config[t]<config[i]; t--);
	swap(config[t], config[i]);
	for(int j=i+1; j<(float)(n+i)/2; j++)
		swap(config[j], config[n+i-j]);
}

//Function displaying all configurations
//(Ham hien thi tat ca cac giao dien)
void listConfig(int n){
	int i;
	do{
		viewConfig(n);
		for(i=n-2; i>=0 && config[i+1]<config[i]; i--);
		if(i >= 0) nextConfig(n,i);
	} while(i >= 0);
}

int main(){
	int n;
	enter(n);
	listConfig(n);
}
