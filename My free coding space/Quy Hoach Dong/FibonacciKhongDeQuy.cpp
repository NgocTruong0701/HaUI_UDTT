#include <iostream>

using namespace std;

//Non-recursive function returning Fibonacci's number number n
//(Ham khong de quy tim so Fibonacci thu n)
unsigned long fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	else{
		int f, f1 = 1, f2 = 1;
		for(int i=3; i<=n; i++){
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		return f;
	}
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
