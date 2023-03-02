#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void longestSubString(char *a, char *b, int **&f){
	int k = strlen(a), l = strlen(b);
	f = new int*[k + 1];
	for(int i = 0; i <= k; i ++)
		f[i] = new int[l + 1];
	for(int i = 0; i <= l; i ++)
		f[0][i] = 0;
	for(int i = 0; i <= k; i ++)
		f[i][0] = 0;
	for(int i = 1; i <= k; i ++)
		for(int j = 1; j <= l; j ++){
			if(a[i-1] == b[j-1])
				f[i][j] = f[i-1][j-1] + 1;
			else{
				if(f[i][j-1] > f[i-1][j])
					f[i][j] = f[i][j-1];
				else
					f[i][j] = f[i-1][j];
			}
		}
	for(int i = 0; i <= k; i ++){
		for(int j = 0; j <= l; j ++)
			cout << setw(4) << f[i][j];
		cout << endl;
	}
}

//void result(char *a, char *b, int **f){
//	int k = strlen(a), l = strlen(b),;
//	while(k){
//		if(f[k][i] != f[k][i+1]){
//			cout << b[i];
//		}
//		k --;
//	}
//}

int main(){
	int **f;
	longestSubString("nguyen linh truong", "tran thi hong tham", f);
//	result("nguyen linh truong", "tran thi hong tham", f);
}
