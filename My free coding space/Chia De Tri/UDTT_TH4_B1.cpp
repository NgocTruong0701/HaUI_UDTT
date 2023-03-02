#include <iostream>
#include <cstring>

using namespace std;

struct Student{
	string name;
	string surname;
	int year;
	string address;
};

int n = 6;
Student list[6] ={
	{"Truong", "Nguyen Linh", 1998, "Hai Duong"},
	{"Tham", "Tran Thi Hong", 2002, "Phu Tho"},
	{"Truong", "Le Ngoc", 2002, "Thanh Hoa"},
	{"Khanh", "Dao Van", 1998, "Hai Duong"},
	{"Hieu", "Nguyen Minh", 1999, "Hai Duong"},
	{"Trang", "Le Thi Huyen", 2002, "Vinh Phuc"}
};
int index[6] = {0, 1, 2, 3, 4, 5};

void mergeSort(int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		int *temp = new int[r-l+1];
		for(int i = l; i <= m; i++) temp[i-l] = index[i];
		for(int i = r; i > m; i--) temp[r+m+1-l-i] = index[i];
		int i = 0, j = r-l;
		for(int k = l; k <= r; k++){
			if(list[temp[i]].name < list[temp[j]].name)
				index[k] = temp[i++];
			else
				index[k] = temp[j--];
		}
	}
}

void displayList(){
	for(int i=0; i<n; i++){
		cout << list[index[i]].surname << " ";
		cout << list[index[i]].name << ", ";
		cout << list[index[i]].year << ", ";
		cout << list[index[i]].address << endl;
	}
}

int binarySearch(int l, int r, string name){
	if(l == r){
		if(list[index[l]].name == name)
			return l;
		else
			return -1;
	}
	else if(l < r){
		int m = (l + r) / 2;
		if(list[index[m]].name == name)
			return m;
		else if(list[index[m]].name > name)
			return binarySearch(l,m-1,name);
		else
			return binarySearch(m+1,r,name);
	}
}

int main(){
	mergeSort(0,n-1);
	cout << "Danh sach sinh vien da duoc sap xep theo ten\n";
	displayList();
	string name;
	cout << "Nhap ten can tim: ";
	cin >> name;
	int i = binarySearch(0,n-1,name);
	if(i >= 0){
		cout << "Sinh vien ten '" << name << "' nam o vi tri thu " << i + 1;
		cout << endl << list[index[i]].surname << " ";
		cout << list[index[i]].name << ", ";
		cout << list[index[i]].year << ", ";
		cout << list[index[i]].address << endl;
	}
}
