#include <iostream>
#include <cstring>

using namespace std;

struct Fly{
	string id; //Ma chuyen bay
	float price; //Gia ve
	int numOfSheet; //So ghe
};

Fly b[6] = {{"FL001", 60, 80}, {"FL002", 70, 90},
			{"FL003", 50, 125}, {"FL004", 85, 110},
			{"FL005", 55, 75}, {"FL006", 100, 95}};

int n = 6;

int config[6];
int use[6] = {0, 0, 0, 0, 0, 0};

//Ham de quy tra ve tong gia ve cac chuyen bay
float sumPrice(int n){
	if(n == 1)
		return b[0].price;
	return b[n-1].price + sumPrice(n-1);
}

//Ham de quy hien thi danh sach cac chuyen bay theo chieu nguoc lai
void reverseDisplay(int n){
	if(n > 0){
		cout << b[n-1].id << " ";
		reverseDisplay(n-1);
	}
}

//Ham tinh so chuyen bay it nhat de cho het p hanh khach cho truoc
bool carry (int n, int p, int &c){
	Fly a[6];
	for(int i=0; i<n; i++)
		a[i] = b[i];
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].numOfSheet < a[j].numOfSheet)
				swap(a[i],a[j]);
	c = 0;
	for(int i=0; i<n && p > 0; i++){
		p -= a[i].numOfSheet;
		c ++;
	}
	if(p <= 0) return true;
	else return false;
}

//Hien thi 1 giao dien
void displayConfig(){
	cout << b[config[1]].id;
	for(int i=2; i<=4; i++)
		cout << ", " << b[config[i]].id;
	cout << endl;
}

//Ham quay lui hien thi tat ca cac phuong an chon ra 4 chuyen bay tu 6 chuyen bay
void track(int i){
	int j;
	for(j=config[i-1] + 1; j<i+2; j++){
		config[i] = j;
		if(i == 4) displayConfig();
		else track(i + 1);
	}
}

void displayList(){
	cout << b[config[0]].id;
	for(int i=1; i<n; i++)
		cout << ", " << b[config[i]].id;
	cout << endl;
}

//Ham quay lui hien thi tat ca cac cach xep 6 chuyen bay
void list(int k){
	for(int i=0; i<n; i++)
		if(!use[i]){
			config[k] = i;
			use[i] = 1;
			if(k == n-1)
				displayList();
			else
				list(k + 1);
			use[i] = 0;
		}
}

int main(){
	int p = 300, c;
	cout << "Tong gia ve: " << sumPrice(n) << endl;
	cout << "Danh sach chuyen bay nguoc lai: ";
	reverseDisplay(n);
	if(carry(n,p,c))
		cout << "\nCan toi thieu " << c << " may bay de cho het " << p << " hanh khach";
	else
		cout << "\nKhong the cho het " << p << " hanh khach";
	cout << "\nCac phuong an chon 4 chuyen bay tu " << n << " chuyen bay tren:\n";
	config[0] = -1;
	track(1);
	cout << "\nCac phuong an sap xep 6 chuyen bay:\n";
	list(0);
}
