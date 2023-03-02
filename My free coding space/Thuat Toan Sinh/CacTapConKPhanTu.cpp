#include <iostream>

using namespace std;

//Declare an integer string (Khoi tao 1 chuoi)
int *config;

//Function enterring the size of 2 sets (Ham nhap kich thuoc cua 2 tap hop)
void enterLength(int &n, int &k){
	do{
		cout << "Enter 2 positive integer numbers which are the size of the base set and the derived set\n";
		cout << "(Nhap 2 so nguyen duong la kich thuoc cua tap co so va tap con)\nn: ";
		cin >> n;
		cout << "k (<= " << n <<"): ";
		cin >> k;
		if(n <= 0 || k <= 0 || k > n)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0 || k <= 0 || k > n);
	config = new int[k];
	for(int i = 0; i < k; i++) //Create first configuration (Tao giao dien dau tien)
		config[i] = i + 1;
}

//Function dislaying a configuration
//(Ham hien thi 1 giao dien)
void viewConfig(int k){
	cout << config[0];
	for(int i = 1; i < k; i++)
		cout << ", " << config[i];
}

//Function generating the next configuration based on the current one
//(Ham sinh cau hinh tiep theo tu cau hinh hien tai)
void nextConfig(int k, int i){
	config[i++] += 1;
	while(i < k){
		config[i] = config[i-1] + 1;
		i ++;
	}
}

//Function listing configurations
//(Ham liet ke cac cau hinh)
void listConfig(int n, int k){
	int i;
	do{
		viewConfig(k);
		cout << endl;
		for(i = k-1; i >= 0 && config[i] == n-k+i+1; i--);
		if (i >= 0) nextConfig(k, i);
	} while(i >= 0);
}

int main(){
	int n, k;
	enterLength(n,k);
	listConfig(n,k);
}
