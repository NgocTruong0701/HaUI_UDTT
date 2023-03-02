#include <iostream>

using namespace std;

//Recursive function returning Fibonacci's number number n
//(Ham de quy tim so Fibonacci thu n)
unsigned long fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

//Function enterring n (Ham nhap n)
void enterN(int &n){
	do{
		cout << "Enter n which is a positive integer number";
		cout << " (Nhap n la mot so nguyen duong): ";
		cin >> n;
		if(n <= 0)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
}

//Function displaying Fibonacci's number number n
//(Ham hien thi so Fibonacci thu n)
void displayFiNum(int n){
	cout << "The " << n;
	if(n % 10 == 1 && (n/10) % 10 != 1) cout << "st";
	else if(n % 10 == 2 && (n/10) % 10 != 1) cout << "nd";
	else if(n % 10 == 3 && (n/10) % 10 != 1) cout << "rd";
	else cout << "th";
	cout << " Fibonacci's number is ";
	cout << "(So Fibonacci thu " << n << " la): " << fibonacci(n) << endl;
}

int main(){
	int n;
	enterN(n);
	displayFiNum(n);
}
