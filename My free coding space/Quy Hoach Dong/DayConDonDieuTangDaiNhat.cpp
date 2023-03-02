#include <iostream>

using namespace std;

//Mang 15 so thuc
float num[15] = {0.25, 1, -1.5, 2, -3.75, -2, 4.1, 0, 9, -7.2, 2, -1, -0.5, 10, 3.8};
int n = 15;

void create(float *l){
	l[0] = l[n+1] = num[0];
	for(int i = 0; i < n; i++){
		l[i+1] = num[i];
		if(l[0] > num[i])
			l[0] = num[i];
		if(l[n+1] < num[i])
			l[n+1] = num[i];
	}
	l[0] --;
	l[n+1] ++;
}

void result(float *l, int *length, int *next){
	cout << length[0] - 2 << endl;
	int i = 0;
	while(next[i] != n+1){
		cout << l[next[i]] << " ";
		i = next[i];
	}	
}

void dayConDonDieuTang(){
	float *l = new float[n+2];
	create(l);
	int *length = new int[n+2];
	int *next = new int[n+1];
	length[n+1] = 1;
	for(int i = n; i >= 0; i--){
		next[i] = n + 1;
		for(int j = n+1; j >= i+1; j--)
			if(l[j] > l[i] && length[j] > length[next[i]])
				next[i] = j;
		length[i] = length[next[i]] + 1;
	}
	result(l,length,next);
}

int main(){
	dayConDonDieuTang();
}
