#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Product{
	char *id; //Ma san pham
	char *name; //Ten san pham
	int w; //Khoi luong san pham
	int v; //Gia tri san pham 
};

Product d[7] = {
	{"SP0001", "ban hoc", 8, 6},
	{"SP0020", "den hoc", 3, 5},
	{"SP0056", "dien thoai iphone", 1,8},
	{"SP0088", "dien thoai samsung", 1, 10},
	{"SP0002", "laptop", 3, 4},
	{"SP0043", "quat cay", 5, 7},
	{"SP0087", "ti vi treo tuong", 8, 8}
};

int n = 7;

//Ham tra ve vi tri co the chen san pham moi
int insert(int l, int r, Product p){
	if(l == r){
		if(strcmp(d[l].name, p.name) >= 0)
			return l;
		else
			return l + 1;
	}
	else{
		int m = (l + r) / 2;
		if(strcmp(d[m].name, p.name) >= 0)
			return insert(l,m,p);
		else
			return insert(m+1,r,p);
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
		int j = i, x = v - 1;
		while(x >= 0 && p[j] == c[x]){
			x --;
			j --;
		}
		if(x < 0){
			count ++;
			i += v;
		}
		else{
			x = ch_in_str(p[j], c);
			if(x < 0)
				i += v;
			else
				i = j + v - x - 1;
		}
		return count;
	}
}

//Ham in ra cac san pham co tu "ti vi"
void find(){
	int i = 0;
	for(; i < n; i ++)
		if(Boyer_Moore_Horspool("ti vi",d[i].name))
			break;
	if(i == n)
		cout << "Khong co san pham ti vi nao\n";
	else{
		cout << "Cac san pham ti vi la:\n";
		for(; i < n; i ++)
			if(Boyer_Moore_Horspool("ti vi",d[i].name))
				cout << d[i].id << endl;
	}
}

//Xau con chung dai nhat
int longestSubString(char *a, char *b){
	int k = strlen(a), l = strlen(b);
	int **f = new int*[k + 1];
	for(int i = 0; i <= k; i ++)
		f[i] = new int[l + 1];
	for(int i = 0; i <= l; i ++)
		f[0][i] = 0;
	for(int i = 0; i <= k; i ++)
		f[i][0] = 0;
	for(int i = 1; i <= k; i ++)
		for(int j = 1; j <= l; j ++){
			if(a[i-1] == b[j-1])
				f[i][j] = f[i-1][j-1] + 1;
			else{
				if(f[i][j-1] > f[i-1][j])
					f[i][j] = f[i][j-1];
				else
					f[i][j] = f[i-1][j];
			}
		}
	return f[k][l];
}

//Cac san pham giong "SP0088"
void similar(){
	int i = 0;
	for(; i < n; i ++)
		if(i != 3 && longestSubString(d[i].name, d[3].name) >= 10)
			break;
	if(i == n)
		cout << "Khong co san pham nao giong \"SP0088\"\n";
	else{
		cout << "Cac san pham giong \"SP0088\" la:\n";
		for(; i < n; i ++)
			if(i != 3 && longestSubString(d[i].name, d[3].name) >= 10)
				cout << d[i].id << endl;
	}
}

int main(){
	Product p = {"SP0005", "chuot logitec", 1, 3};
	int m = insert(0,n-1,p);
	if(m == 0)
		cout << "Can chen p vao vi tri dau tien\n";
	else if(m == n)
		cout << "Can chen p vao vi tri cuoi cung\n";
	else
		cout << "Can chen p vao vi tri thu " << m + 1 << endl;
	similar();
	find();
}
