#include <iostream>

using namespace std;

//Declare an array (Khai bao 1 mang)
int *arr;

//Function creating a list (Ham tao 1 mang)
void createArr(int &n){
	do{
		cout << "Enter a positive integer number which is the size of the list\n";
		cout << "(Nhap vao 1 so nguyen duong la kich thuoc cua day): ";
		cin >> n;
		if(n <= 0)
			cout << "Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
	arr = new int[n];
	for(int i=0; i<n; i++){
		cout << "Nhap phan tu thu " << i+1 << ": ";
		cin >> arr[i];
	}
}

//Function displaying list (Ham hien thi danh sach)
void displayList(int n){
	cout << arr[0];
	for(int i=1; i<n; i++)
		cout << ", " << arr[i];
}

//Recursive function returning sum of all odd numbers in the list
//(Ham de quy tra ve tong tat ca cac phan tu le trong day)
int sumOddEle(int n){
	if(n == 1){
		if(arr[n-1]%2 != 0)
			return arr[n-1];
		else
			return 0;
	}
	else{
		if(arr[n-1]%2 != 0)
			return sumOddEle(n-1) + arr[n-1];
		else
			return sumOddEle(n-1);
	}
}

int main(){
	int n;
	createArr(n);
	cout << "Day da nhap la: ";
	displayList(n);
	cout << endl << sumOddEle(n);
}
