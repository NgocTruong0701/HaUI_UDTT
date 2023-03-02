#include <iostream>

using namespace std;

//Mang 15 so thuc
float num[15] = {0.25, 1, -1.5, 2, -3.75, -2, 4.1, 0, 9, -7.2, 2, -1, -0.5, 10, 3.8};
int n = 15;

float maxSearch(int l, int r){
	if(l == r)
		return num[l];
	else if(l < r){
		int m = (l + r) / 2;
		if(maxSearch(l,m) > maxSearch(m+1,r))
			return maxSearch(l,m);
		else
			return maxSearch(m+1,r);
	}
}

int main(){
	cout << maxSearch(0,n-1);
}
