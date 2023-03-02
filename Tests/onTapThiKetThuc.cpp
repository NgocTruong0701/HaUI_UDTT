#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//Dinh nghia 1 thung hang
struct Bin{
	char *id; //Ma thung hang
	int m; //Khoi luong thung hang
	int p; //GIa tri thung hang
};

int n = 6;

//Danh sach 6 thung hang
Bin d[6] = {
	{"P001", 4, 5},
	{"P003", 6, 3},
	{"P004", 8, 6},
	{"P002", 7, 10},
	{"P006", 5, 7},
	{"P005", 4, 8}
};

//Ham quy hoach dong
void dynamic(int **&f, int m){
	f = new int*[n+1];
	for(int i = 0; i <= n; i ++)
		f[i] = new int[m+1];
	for(int i = 0; i <= m; i ++)
		f[0][i] = 0;
	int temp;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= m; j ++){
			f[i][j] = f[i-1][j];
			temp = f[i-1][j-d[i-1].m] + d[i-1].p;
			if(j >= d[i-1].m && temp > f[i][j])
				f[i][j] = temp;
		}
}

void table(int **f, int m){
	cout << "Bang phuong an:\n";
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= m; j ++)
			cout << setw(4) << f[i][j];
		cout << endl; 
	}
}

void result(int **f, int m){
	cout << "Gia tri lon nhat khi xep cac thung hang la: " << f[n][m] << endl;
	cout << "Cac thung hang duoc xep len la:\n";
	int i = n, j = m;
	while(i){
		if(f[i][j] != f[i-1][j]){
			cout << "- " << d[i-1].id << endl;
			j -= d[i-1].m;
		}
		i --;
	}
}

int ch_in_str(char ch, char *str){
	int i = 0;
	while(str[i] != '\0'){
		if(ch == str[i])
			return i;
		i ++;
	}
	return -1;
}

int Boyer_Moore_Horspool(char *c, char *p){
	int v = strlen(c), i = strlen(c) - 1, count = 0;
	while(i < strlen(p)){
		int x = v - 1, j = i;
		while(x >= 0 && c[x] == p[j]){
			x --;
			j --;
		}
		if(x < 0){
			i += v;
			count ++;
		}
		else{
			x = ch_in_str(p[j],c);
			if(x < 0)
				i += v;
			else
				i = j + v - x - 1;
		}
	}
	return count;
}

int subStr(char *c, char *p){
	int n = strlen(c), m = strlen(p);
	int **f= new int[n + 1];
	for(int i = 0; i <= n; i ++)
		f[i] = new int[m + 1];
	for(int i = 0; i )
}

int main(){
	int m = 22; //Khoi luong toi da ma xe cho duoc
	int **f; //Mang 2 chieu chua bang phuong an
	dynamic(f,m);
	table(f,m);
	result(f,m);
	cout << Boyer_Moore_Horspool("abc", "abcdab");
}
