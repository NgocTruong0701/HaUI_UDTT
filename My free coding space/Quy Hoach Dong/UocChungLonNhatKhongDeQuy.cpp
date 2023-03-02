#include <iostream>

using namespace std;

//Non-recursive function returnning the greatest common divisor of 2 number
//(Ham khong de quy tra ve uoc chung lon nhat cua 2 so)
int GCD(int a, int b){
	int r = a % b;
	while(r > 0){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

//Function enterring 2 positive integer numbers (Ham nhap 2 so nguyen duong)
void enter(int &a, int &b){
	do{
		cout << "Enter 2 positive integer numbers (Nhap 2 so nguyen duong)\na: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		if(a <= 0 || b <= 0)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(a <= 0 || b <= 0);
}

//Function displaying the result (Ham hien thi ket qua)
void output(int a, int b){
	cout << "The greatest common divisor of " << a << " and " << b << " is: " << GCD(a,b);
	cout << "\n(Uoc chung lon nhat cua " << a << " va " << b << " la: " << GCD(a,b) << ")\n";
}

int main(){
	int a, b;
	enter(a,b);
	output(a,b);
}
