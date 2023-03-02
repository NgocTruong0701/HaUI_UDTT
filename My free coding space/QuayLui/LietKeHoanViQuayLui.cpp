#include <iostream>

using namespace std;

int *config, *use;

//Function enterring the string's length (Ham nhap do dai chuoi)
void enterLength(int &n){
	do{
		cout << "Enter a positive integer number which is the length of the string\n";
		cout << "(Nhap mot so nguyen duong la do dai cua chuoi): ";
		cin >> n;
		if(n <= 0)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
	config = new int[n];
	use = new int[n];
	for(int i=0; i<n; i++)
		use[i] = 0;
}

//Function dislaying a configuration
//(Ham hien thi 1 giao dien)
void viewConfig(int n){
	for(int i = 0; i < n; i++)
		cout << config[i];
	cout << endl;
}

//Function listing configurations
//(Ham liet ke cac cau hinh)
void listConfig(int k, int n){
	for(int i=0; i<n; i++){
		if(!use[i]){
			config[k] = i;
			use[i] = 1;
			if(k == n-1)
				viewConfig(n);
			else
				listConfig(k+1,n);
			use[i] = 0;
		}
	}
}


int main(){
	int n;
	enterLength(n);
	listConfig(0,n);
}
