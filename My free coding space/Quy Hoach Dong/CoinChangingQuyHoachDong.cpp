#include <iostream>

using namespace std;

int c[4] = {1, 2, 5, 10};
int n = 4;


void result(int m, int *f, int *s){
	cout << "So tien: " << m << endl;
	cout << "Can toi thieu " << f[m] << " to tien" << endl;
	cout << "Cac to tien:";
	while(m){
		int t = c[s[m]];
		cout << " " << t;
		m -= t;
	}
	cout << endl;
}

void coinChanging(int m){
	int *f = new int[m + 1];
	int *s = new int[m + 1];
	for(int i = 0; i < n; i++)
		s[i] = 0;
	f[0] = 0;
	for(int i = 1; i <= m; i++){
		int min = m/c[0];
		for(int j = 0; j < n; j++){
			if(f[i - c[j]] + 1 < min && c[j] <= i){
				min = f[i - c[j]] + 1;
				s[i] = j;
			}
		}
		f[i] = min;
	}
	result(m,f,s);
}

int main(){
	cout << "Cac menh gia tien:";
	for(int i = 0; i < n; i++)
		cout << " " << c[i];
	cout << endl;
//	for(int i = 0; i <= 30; i = i + 3){
//		coinChanging(i);
//	}
	coinChanging(16);
}
