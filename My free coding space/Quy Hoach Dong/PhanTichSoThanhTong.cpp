#include <iostream>

using namespace std;

void input(int &n, int &m){
	do{
		cout << "Nhap n: ";
		cin >> n;
		if(n <= 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n <= 0);
	do{
		cout << "Nhap m: ";
		cin >> m;
		if(m < 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(m < 0);
}

int PTSoThanhTong(int n, int m){
	int *f = new int[n + 1];
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		f[i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = i; j <= n; j++)
			if(j >= i)
				f[j] = f[j] + f[j - i];
	return f[n];
}

void viewConfig(int n, int *config){
	cout << "- " << n << " = ";
	cout << config[0];
	for(int i = 1; i < n && config[i] != 0; i++)
		cout << " + " << config[i];
	cout << endl;
}

void firstConfig(int n, int m, int *config){
	if(m > n)
		config[0] = n;
	else
		config[0] = m;
	if(n > 1){
		config[1] = n - config[0];
		for(int i = 2; i < n; i ++)
			config[i] = 0;
	}
}

void nextConfig(int n, int *config){
	int i = n - 1, s = n;
	for(; config[i] == 0 || config[i] == 1; i--);
	config[i] --;
	for(int j = 0; j <= i; j++)
		s -= config[j];
	i ++;
	for(; s > 0; i++){
		if(s < config[i-1])
			config[i] = s;
		else
			config[i] = config[i-1];
		s -= config[i-1];
	}
	for(; i < n; i++)
		config[i] = 0;
}

void listConfig(int n, int m){
	int *config = new int[n];
	firstConfig(n,m,config);
	viewConfig(n,config);
	while(config[0] != 1){
		nextConfig(n,config);
		viewConfig(n,config);
	}
}

int main(){
	int m, n;
	input(n,m);
	cout << "Co " << PTSoThanhTong(n,m) << " cach phan tich so " << n;
	cout << " thanh tong cua cac so nho hon hoac bang " << m << endl;
	if(PTSoThanhTong(n,m)){
		cout << "Do la:\n";
		listConfig(n,m);
	}
}
