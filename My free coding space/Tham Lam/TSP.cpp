#include <iostream>

using namespace std;

void input(int &n, int **&l, int &s, int &f){
	do{
		cout << "Nhap so dia diem: ";
		cin >> n;
		if(n < 2)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 2);
	l = new int*[n];
	for(int i=0; i<n; i++)
		l[i] = new int[n];
	for(int i=0; i<n-1; i++){
		l[i][i] = 0;
		for(int j=i+1; j<n; j++){
			do{
				cout << "Nhap chi phi tu dia diem " << i << " ==> dia diem " << j << ": ";
				cin >> l[i][j];
				if(l[i][j] < 0)
					cout << "Nhap sai. Nhap lai!\n";
			} while(l[i][j] < 0);
			l[j][i] = l[i][j];
		}
	}
	l[n-1][n-1] = 0;
	do{
		cout << "Nhap dia diem xuat phat (0 -> " << n-1 << "): ";
		cin >> s;
		if(s < 0 || s >= n)
			cout << "Nhap sai. Nhap lai!\n";
	} while(s < 0 || s >= n);
	do{
		cout << "Nhap dia diem ket thuc khac voi diem xuat phat (0 -> " << n-1 << "): ";
		cin >> f;
		if(f < 0 || f >= n || f == s)
			cout << "Nhap sai. Nhap lai!\n";
	} while(f < 0 || f >= n || f == s);
}

void track(int n, int **l, int s, int f){
	int *d = new int[n];
	int *check = new int[n];
	int *last = new int[n];
	for(int i=0; i<n; i++){
		d[i] = l[s][i];
		check[i] = 0;
		last[i] = s;
	}
	check[s] = 1;
	while(!check[f]){
		int min = 0;
		for(int i=0; i<n; i++){
			if(d[min] == 0)
				min = i+1;
			else if(!check[i] && d[i] != 0 && d[i] < d[min])
				min = i;
		}
		check[min] = 1;
		if(!check[f])
			for(int i=0; i<n; i++)
				if(!check[i] && l[i][min] != 0 && (d[i] == 0 || (d[i] != 0 && l[i][min] + d[min] < d[i]))){
					d[i] = l[i][min] + d[min];
					last[i] = min;
				}
	}
	cout << "Duong di tu dia diem " << s << " den dia diem " << f << " la: ";
	cout << f;
	int i = last[f];
	while(i != s){
		cout << " <== " << i+1;
		i = last[i];
	}
}

int main(){
	int n, **l, s, f;
	input(n,l,s,f);
	track(n,l,s,f);
}
