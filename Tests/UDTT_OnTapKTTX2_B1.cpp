#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//Dinh nghia 1 chiec dien thoai
struct Phone{
	string brand;
	int size;
	float price;
};

int n = 6;
Phone d[6] = {
	{"brand1", 6, 7.5},
	{"brand2", 5, 9},
	{"brand3", 4, 5.25},
	{"brand4", 7, 6.75},
	{"brand5", 6, 10},
	{"brand6", 4, 8.5}
};

void algorithm(int s, float **f){
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= s; j++){
			f[i][j] = f[i-1][j];
			float temp = f[i-1][j-d[i-1].size] + d[i-1].price;
			if(temp > f[i][j] && d[i-1].size <= j)
				f[i][j] = temp;
		}
}

void result(int s, float **f){
	int i = n, j = s;
	while(i){
		if(f[i][j] != f[i-1][j]){
			cout << setw(10) << d[i-1].brand << setw(6) << d[i-1].size;
			cout << setw(6) << d[i-1].price << endl;
			j -= d[i-1].size;
		}
		i --;
	}
}

void dynamicSelect(int s){
	float **f = new float*[n + 1];
	for(int i = 0; i <= n; i++)
		f[i] = new float[s + 1];
	for(int i = 0; i <= s; i++)
		f[0][i] = 0;
	algorithm(s,f);
	cout << "Cac dien thoai can lay de duoc gia tri lon nhat la:\n";
	result(s,f);
}

int count(int l, int r){
	if(l == r){
		if(d[l].price <= 6 && d[l].price >= 3)
			return 1;
		else return 0;
	}
	else{
		int m = (l + r) / 2;
		return count(l,m) + count(m+1,r);
	}
}


int main(){
	int s = 12;
	dynamicSelect(s);
	cout << "\nSo dien thoai co gia trong khoang 3 den 6 trieu: " << count(0,n-1);
}
