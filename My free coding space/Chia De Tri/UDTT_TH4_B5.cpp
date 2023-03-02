#include <iostream>

using namespace std;

//Mang 15 so thuc
float num[15] = {0.25, 1, -1.5, 2, -3.75, -2, 4.1, 0, 9, -7.2, 2, -1, -0.5, 10, 3.8};
int n = 15;

float sumPositive(int l, int r){
	if(l == r){
		if(num[l] > 0)
			return num[l];
		else
			return 0;
	}
	else if(l < r){
		int m = (l + r) / 2;
		return sumPositive(l,m) + sumPositive(m+1,r);
	}
}

int main(){
	cout << sumPositive(0, n-1);
}
