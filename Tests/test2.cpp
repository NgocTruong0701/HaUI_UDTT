#include <iostream>
#include <cstring>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Screen{
	char *brand;
	int size;
	int weight;
};

int n = 7;

Screen d[7] = {
	{"toshiba", 20, 6},
	{"mitsubishi", 18, 5},
	{"asus", 24, 10},
	{"panasonic", 22, 8},
	{"acer", 21, 10},
	{"hp", 20, 9},
	{"dell", 18, 6}
};

//Tim man hinh co kich thuoc lon nhat
int max(int l, int r){
	if(l == r)
		return l;
	else{
		int m = (l + r) / 2;
		if(d[max(l,m)].size > d[max(m+1,r)].size)
			return max(l,m);
		else
			return max(m+1,r);
	}
}

//Quy hoach dong
void dynamic(int m, int **f){
	int temp;
	for(int i = 0; i <= m; i++)
		f[0][i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			temp = f[i-1][j-d[i-1].weight] + d[i-1].size;
			if(d[i-1].weight < j && f[i][j] < temp)
				f[i][j] = temp;
		}
}

//Hien thi bang ket qua
void table(int m, int **f){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++)
			cout << setw(5) << f[i][j];
		cout << endl;
	}	
}

//Ket qua
void output(int m, int **f){
	cout << "Tong kich thuoc lon nhat lay duoc: " << f[n][m];
	cout << "\nCac man hinh lay duoc:\n";
	int i = n, j = m;
	while(i){
		if(f[i][j] != f[i-1][j]){
			cout << "- Man hinh so " << i << ": ";
			cout << setw(15) << d[i-1].brand << setw(6) << d[i-1].size << setw(6) << d[i-1].weight << endl;
			j -= d[i-1].weight;
		}
		i --;
	}
}

int main(){
	cout << "Man hinh co kich thuoc lon nhat la man hinh thu " << max(0,n-1) + 1 << ": ";
	cout << d[max(0,n-1)].brand << " - " << d[max(0,n-1)].size << " - " << d[max(0,n-1)].weight << endl;
	int m = 20;
	int **f;
	f = new int*[n + 1];
	for(int i = 0; i < n; i++)
		f[i] = new int[m + 1];
	dynamic(m,f);
	table(m,f);
	output(m,f);
}
