#include <iostream>
#include <string.h>

using namespace std;

//Create list (Tao danh sach)
string str[6] = {"Trang","Cong","Trung","Binh","Hoan","Mai"};

//Declare a configuration (Khoi tao giao dien)
int config[4];

//Function dislaying a configuration
//(Ham hien thi 1 giao dien)
void viewConfig(int k){
	cout << str[config[0]];
	for(int i = 1; i < k; i++)
		cout << ", " << str[config[i]];
	cout << endl;
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
	for(i = 0; i < k; i++) //Create first configuration (Tao cau hinh dau tien)
		config[i] = i;
	do{
		viewConfig(k);
		for(i = k-1; i >= 0 && config[i] == n-k+i; i--);
		if (i >= 0) nextConfig(k, i);
	} while(i >= 0);
}

int main(){
	int n = 6, k = 4;
	listConfig(n,k);
}
