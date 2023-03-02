#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

#define max 100

int n = 6;
char d[6][max] = {
	"linh truong", //11
	"trung kien", //10
	"hong tham", //9
	"ngoc truong", //11
	"childest", //9
	"huyen trang" //11
};
int index[6] = {0, 1, 2, 3, 4, 5};

int shortest(int l, int r){
	if(l == r)
		return l;
	else {
		int m = (l + r) / 2;
		if(strlen(d[shortest(l,m)]) < strlen(d[shortest(m+1,r)]))
			return shortest(l,m);
		else
			return shortest(m+1,r);
	}
}

int sumSize(int l, int r){
	if(l == r)
		return strlen(d[l]);
	else{
		int m = (l + r) / 2;
		return sumSize(l,m) + sumSize(m+1,r);
	}
}

void mergeSort(int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		int *b = new int[r-l+1];
		for(int i = 0; i <= m-l; i++)
			b[i] = index[i+l];
		for(int i = r-l; i > m-l; i--)
			b[i] = index[m+r+1-i-l];
		int j = 0, k = r-l;
		for(int i = l; i <= r; i++){
			if(strcmp(d[b[j]],d[b[k]]) > 0)
				index[i] = b[k--];
			else
				index[i] = b[j++];
		}	
	}
}

void show(){
	for(int i = 0; i < n; i++)
		cout << d[index[i]] << endl;
}

int search(int l, int r, char st[max]){
	if(l == r){
		if(strcmp(d[index[l]],st) == 0)
			return l;
		else
			return -1;
	}
	else{
		int m = (l + r) / 2;
		if(strcmp(d[index[m]],st) == 0)
			return m;
		else if(strcmp(d[index[m]],st) > 0)
			return search(l,m-1,st);
		else
			return search(m+1,r,st);
	}
}

int char_in_string(char ch, char *str){
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == ch)
			return i;
		i ++;
	}
	return -1;
}

//Boyer Moore Horspool
int Boyer_Moore_Horspool(char *t, char *p){
	int count = 0, i = strlen(p) - 1, v = strlen(p);
	while(i < strlen(t)){
		int x = v - 1, j = i;
		while(p[x] == t[j] && x > -1){
			x --;
			j --;
		}
		if(x < 0){
			count ++;
			i += v;
		}
		else{
			x = char_in_string(t[j],p);
			if(x < 0)
				i += v;
			else
				i = j + v - x - 1;
		}
	}
	return count;
}

void count(){
	int count = 0;
	for(int i = 0; i < n; i++)
		if(Boyer_Moore_Horspool(d[i], "child") != 0)
			count ++;
	if(count == 0)
		cout << "\n\"child\" khong xuat hien trong d.";
	else{
		cout << "\n\"child\" xuat hien " << count << " lan trong d.\n";
		for(int i = 0; i < n; i++)
			if(Boyer_Moore_Horspool(d[i], "child") != 0)
				cout << d[i] << endl;
	}
}

int main(){
	cout << "Xau ngan nhat: '" << d[shortest(0,n-1)] << "'\n";
	cout << "Tong chieu dai tat ca cac xau: " << sumSize(0,n-1);
	mergeSort(0,n-1);
	cout << "\nCac xau da sap xep:\n";
	show();
	char st[max];
	cout << "Nhap st: ";
	gets(st);
	if(search(0,n-1,st) < 0)
		cout << "'" << st << "' khong xuat hien trong danh sach";
	else
		cout << "'" << st << "' xuat hien o vi tri thu " << search(0,n-1,st) + 1;
	count();
}

