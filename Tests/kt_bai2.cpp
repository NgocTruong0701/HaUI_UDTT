#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Class{
	char *id; //Ma lop
	int num; //So hoc sinh
	int num_fem; //So hoc sinh nu
};

int m = 7;
Class d[7] = {
	{"it001", 25, 15},
	{"it007", 25, 10},
	{"a005", 22, 12},
	{"it002", 20, 5},
	{"b004", 18, 8},
	{"it003", 16, 10},
	{"c006", 15, 7}
};

//Ham tham lam cho biet can it nhat bao nhieu lop trong d de duoc so hoc sinh lon hon n
int greedy(int n){
	int i = 0;
	while(n >= 0 && i < m)
		n -= d[i++].num;
	return i;
}

//Ham quy hoach dong
void dynamic(int **&f, int k){
	f = new int *[m+1];
	for(int i = 0; i <= m; i ++)
		f[i] = new int[k+1];
	for(int i = 0; i <= k; i ++)
		f[0][i] = 0;
	int temp;
	for(int i = 1; i <= m; i ++)
		for(int j = 0; j <= k; j ++){
			f[i][j] = f[i-1][j];
			temp = f[i-1][j-d[i-1].num] + d[i-1].num_fem;
			if(d[i-1].num <= j && temp > f[i][j])
				f[i][j] = temp;
		}
}

//Bang phuong an
//void table(int **f, int k){
//	for(int i = 0; i <= m; i ++){
//		for(int j = 0; j <= k; j ++)
//			cout << setw(5) << f[i][j];
//		cout << endl;
//	}
//}

//Ham in ra ket qua quy hoach dong
void output(int **f, int k){
	int i = m, j = k;
	while(i){
		if(f[i][j] != f[i-1][j]){
			cout << d[i-1].id << endl;
			j -= d[i-1].num;
		}
		i --;
	}
}

//Ham tra ve vi tri cua ki tu ch trong xau str
int ch_in_str(char ch, char *str){
	int i = 0;
	while(str[i] != '\0'){
		if(ch == str[i])
			return i;
		i ++;
	}
	return -1;
}

//Ham tra ve so lan xuat hien cua xau s trong xau st
int Boyer_Moore_Horspool(char *s, char *st){
	int v = strlen(s), i = strlen(s) - 1, count = 0;
	while(i < strlen(st)){
		int x = v - 1, j = i;
		while(x >= 0 && s[x] == st[j]){
			x --;
			j --;
		}
		if(x < 0){
			count ++;
			i += v;
		}
		else{
			x = ch_in_str(st[j],s);
			if(x < 0)
				i += v;
			else
				i = j + v - x - 1;
		}
	}
	return count;
}

//Ham in ra cac lop thuoc nganh cong nghe thong tin
void findIT(){
	int i = 0;
	for(; i < m; i ++)
		if(Boyer_Moore_Horspool("it", d[i].id))
			break;
	if(i == m)
		cout << "Khong co lop hoc nao thuoc nganh cong nghe thong tin\n";
	else{
		cout << "Cac lop thuoc nganh cong nghe thong tin trong d la:\n";
		for(; i < m; i ++)
			if(Boyer_Moore_Horspool("it", d[i].id))
				cout << d[i].id << endl;
	}
			
}

int main(){
	int n = 60, k = 70;
	cout << "Can it nhat " << greedy(n) << " lop de duoc so hoc sinh lon hon " << n << endl;
	int **f; //Mang 2 chieu chua bang phuong an
	dynamic(f,k);
	cout << "Nhung lop can ghep vao phong hoc p co " << k;
	cout << " cho ngoi de duoc so hoc sinh nu lon nhat la:\n";
	output(f,k);
	cout << "So hoc sinh nu lon nhat la: " << f[m][k] << endl;
	findIT();
}
