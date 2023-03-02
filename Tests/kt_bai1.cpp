#include <iostream>

using namespace std;

int a[15] = {-2, 5, 10, 2, 3, -4, 0, 4, 1, -5, -8, 7, 1, -1, 5};

int n = 15;

// Ham chia de tri tim so nho nhat m trong a sao cho m > k
int search(int l, int r, int k){
	if(l == r){
		if(a[l] > k)
			return l;
		else
			return -1;
	}
	else{
		int m = (l + r) / 2;
		int left = search(l,m,k), right = search(m+1,r,k);
		if(left > 0 && right > 0){
			if(a[left] < a[right])
				return left;
			else
				return right;
		}
		else if(left > 0)
			return left;
		else if(right > 0)
			return right;
		else
			return -1;
	}
}

int main(){
	int k = 2;
	int m = search(0,n-1,k);
	if(m < 0)
		cout << "Khong co phan tu nao lon hon " << k << " trong mang a\n";
	else
		cout << "So m > " << k << " nho nhat trong mang a la: " << a[m] << endl;
}
