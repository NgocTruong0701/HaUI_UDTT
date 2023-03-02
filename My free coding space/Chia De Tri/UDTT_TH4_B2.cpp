#include <iostream>

using namespace std;

//Mang 15 so thuc
float num[15] = {0.25, 1, -1.5, 2, -3.75, -2, 4.1, 0, 9, -7.2, 2, -1, -0.5, 10, 3.8};
int n = 15;

void mergeSort(int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		float *temp = new float[r-l+1];
		for(int i = l; i <= m; i++) temp[i-l] = num[i];
		for(int i = r; i > m; i--) temp[r+m+1-l-i] = num[i];
		int i = 0, j = r-l;
		for(int k = l; k <= r; k++){
			if(temp[i] < temp[j])
				num[k] = temp[i++];
			else
				num[k] = temp[j--];
		}
	}
}

void displayList(){
	cout << num[0];
	for(int i=1; i<n; i++){
		cout << ", " << num[i];
	}
}

int main(){
	mergeSort(0, n-1);
	displayList();
}
