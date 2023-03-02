#include <iostream>

using namespace std;

float power(float a, int n){
	if(n == 0)
		return 1;
	else if(n % 2 == 0)
		return power(a,n/2) * power(a,n/2);
	else
		return power(a,n/2) * power(a,n/2)*a;
}



int main(){
	cout << power(0.5, 3);
}
