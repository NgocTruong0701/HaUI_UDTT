#include <iostream>

using namespace std;

//Function returning sum of all digits of a positive integer number
//(Ham tra ve tong cac chu so cua 1 so nguyen duong)
long sum(long n){
	if(n < 10)
		return n;
	return sum(n/10) + n%10; 
}

//Recursive function enterring a positive integer number
//(Ham nhap vao 1 so nguyen duong)
void enter(long &n){
	do{
		cout << "Enter a positive integer number (Nhap vao 1 so nguyen duong): ";
		cin >> n;
		if(n <= 0)
			cout << "Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
}

int main(){
	long n;
	enter(n);
	cout << sum(n);
}
