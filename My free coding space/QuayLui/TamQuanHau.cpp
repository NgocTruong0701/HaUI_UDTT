#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int n = 8, count = 1;;
int *row = new int[n];

bool safety(int r, int c){
	for(int i=0; i<r; i++)
		if(c == row[i] || abs(c-row[i]) == abs(r-i))
			return false;
	return true;
}

void view(){
	cout << "        (" << row[0] + 1;
	for(int i=1; i<n; i++)
		cout << ", " << row[i] + 1;
	cout << ")\n\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(row[i] == j)
				cout << "    -";
			else
				cout << "    *";
		}
		cout << endl << endl;
	}
}

void track(int k){
	for(int i=0; i<8; i++){
		if(safety(k,i)){
			row[k] = i;
			if(k == n-1){
				cout << "        ----------" << count++ << "----------\n";
				view();
			}
			track(k+1);
		}
	}
}

int main(){
	track(0);
}
