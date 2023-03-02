#include <iostream>

using namespace std;

//Mang 15 so nguyen
int num[15] = {-2, 0 , 1, -6, 8, 3, -5, 7, 6, 10, 20, -10, 15, 7, -8};
int n = 15;

int minEven(int l, int r){
	if(l == r){
		if(num[l]%2 == 0 && num[l] != 0)
			return num[l];
		else
			return 0;
	}
	else if(l < r){
		int m = (l + r) / 2;
		if(minEven(l,m) == 0)
			return minEven(m+1,r);
		else if(minEven(m+1,r) == 0)
			return minEven(l,m);
		else if(minEven(l,m) < minEven(m+1,r))
			return minEven(l,m);
		else
			return minEven(m+1,r);
	}
}

int main(){
	if(minEven(0,n-1) == 0)
		cout << "Khong co so chan nao!\n";
	else
		cout << "So chan nho nhat la: " << minEven(0, n-1);
}
