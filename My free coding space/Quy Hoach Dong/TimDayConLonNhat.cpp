#include <iostream>
#include <iomanip>

using namespace std;


//Display problem (Hien thi bai toan)
void introduceProblem(){
	cout << right << setw(35) << "---------- Problem ----------\n";
	cout << "Enter an integer array.\n";
	cout << "A subsequence is a segment of consecutive elements of the array.\n";
	cout << "Find the subsequence whose sum is the biggest.\n";
	cout << "(" << right << setw(34) << "---------- Bai toan ----------\n";
	cout << "Nhap vao mot mang so nguyen.\n";
	cout << "Mot day con la mot doan cac phan tu lien tiep cua mang.\n";
	cout << "Tim day con co tong cac phan tu la lon nhat.)\n";
}

//Declare an array (Khai bao 1 mang)
int *a;

//Function creating array (Ham tao mang)
void createArr(int &n){
	do{
		cout << "\nEnter a positive integer number which is the number of array's elements\n";
		cout << "(Nhap mot so nguyen duong la so phan tu cua mang): ";
		cin >> n;
		if(n <= 0)
			cout << " Wrong input. Enter again! (Nhap sai. Nhap lai!)\n";
	} while(n <= 0);
	a = new int(n);
	for(int i = 0; i < n; i ++){
		cout << "Enter the " << i + 1;
		if(i % 10 == 0  && (n/10) % 10 != 1) cout << "st ";
		else if(i % 10 == 1  && (n/10) % 10 != 1) cout << "nd ";
		else if(i % 10 == 2  && (n/10) % 10 != 1) cout << "rd ";
		else cout << "th ";
		cout << "element of array (Nhap phan tu thu " << i + 1 <<  " cua mang): ";
		cin >> a[i];
	}
}

// Function finding the biggest subsequence (Ham tim day con lon nhat)
void maxSubSeq(int n, int &l, int &r, long &max){
	max = a[0];
	for(int i = 0; i < n; i ++){
		long s = 0;
		for(int j = i; j < n; j ++){
			s += a[j];
			if(s > max){
				max = s;
				l = i;
				r = j;
			}
		}
	}
}

//Function displaying the biggest subsequence (Ham hien thi day con lon nhat)
void displayMaxSubSeq(int n){
	int l, r;
	long max;
	maxSubSeq(n,l,r,max);
	cout << "\nThe biggest subsequence is (Day con lon nhat la): ";
	cout << "s(" << l + 1 << ", " << r + 1 << ") = (";
	for(int i = l; i < r; i ++)
		cout << a[i] << ", ";
	cout << a[r] << ")\nWhose sum is (Co tong la): w(s(";
	cout << l + 1 << ", " << r + 1 << ")) = " << max << endl;
}

int main(){
	int n;
	introduceProblem();
	createArr(n);
	displayMaxSubSeq(n);
}
