#include <iostream>
#include <iomanip>

using namespace std;

//Display problem (Hien thi bai toan)
void introduceProblem(){
	cout << right << setw(35) << "---------- Problem ----------\n";
	cout << "Enter an integer number n.Then:\n";
	cout << "- Find Fibonacci's number number n.\n";
	cout << "- Display the first n Fibonacci's numbers.\n";
	cout << "- Display the sum of the first n Fibonacci's numbers.)\n";
	cout << "(" << right << setw(34) << "---------- Bai toan ----------\n";
	cout << "Nhap vao mot so nguyen duong n. Hay:\n";
	cout << "- Tim so Fibonacci thu n.\n";
	cout << "- Hien thi n so Fibonacci dau tien.\n";
	cout << "- Hien thi tong cua n so Fibonacci dau tien.)\n";
}

//Declare an array (Khai bao 1 mang)
unsigned long *m;

//Function enterring n (Ham nhap n)
void enterN(int &n){
	do{
		cout << "\nEnter n which is a positive integer number";
		cout << " (Nhap n la mot so nguyen duong): ";
		cin >> n;
		if(n <= 0)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
	m = new unsigned long[n];
}

//Remembering recursive function returning Fibonacci's number number n
//(Ham de quy co nho tra ve so Fibonacci thu n)
unsigned long fibonacci(int n){
	if(n == 1 || n == 2)
		m[n - 1] = 1;
	else
		m[n - 1] = fibonacci(n-1) + fibonacci(n-2);
	return m[n - 1];
}

//Function displaying Fibonacci's number number n
//(Ham hien thi so Fibonacci thu n)
void displayFiNum(int n){
	cout << "\nThe " << n;
	if(n % 10 == 1 && (n/10) % 10 != 1) cout << "st";
	else if(n % 10 == 2 && (n/10) % 10 != 1) cout << "nd";
	else if(n % 10 == 3 && (n/10) % 10 != 1) cout << "rd";
	else cout << "th";
	cout << " Fibonacci's number is ";
	cout << "(So Fibonacci thu " << n << " la): " << fibonacci(n) << endl;
}

//Function displaying the first n Fibonacci's numbers
//(Ham hien thi n so Fibonacci dau tien)
void displayFiboList(int n){
	cout << "\nList of the first " << n << " Fibonacci's numbers " ;
	cout << "(Day " << n << " so Fibonacci dau tien): ";
	for(int i = 0; i < n-1; i ++)
		cout << m[i] << ", ";
	cout << m[n-1] << endl;
}

//Function returning the sum of the first n Fibonacci's numbers
// (Ham tra ve tong cua n so Fibonacci dau tien)
unsigned long sum(int n){
	unsigned long s = 0;
	for(int i = 0; i < n; i ++)
		s += m[i];
	return s;
}
/*
//Recursive function returning the sum of the first n Fibonacci's numbers
//(Ham de quy tra ve tong cua n so Fibonacci dau tien)
unsigned long sum(int n){
	if(n == 1)
		return m[0];
	else
		return m[n - 1] + sum(n-1);
}
*/

//Function displaying the sum of the first n Fibonacci's numbers
//(Ham hien thi tong cua n so Fibonacci dau tien)
void displaySum(int n){
	cout << "\nThe summary of the first n Fibonacci's numbers ";
	cout << "(Tong cua " << n << " so Fibonacci dau tien): " << sum(n) << endl;
}

int main(){
	int n;
	introduceProblem();
	enterN(n);
	displayFiNum(n);
	displayFiboList(n);
	displaySum(n);
}
