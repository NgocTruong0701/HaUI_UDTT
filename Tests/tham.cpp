#include<bits/stdc++.h>
using namespace std;

struct book{
	string nameBook;
	int cost;
	char *nameAuthor;
};

int n = 7;

book d[7] = {   {"Co so du lieu", 120, "Pham Kim Phuong"},
				{"CTDL&GT", 50, "Tran Thi Thuy"},
				{"Lap trinh can ban", 160, "Nguyen Thi Hoa"},
				{"Lap trinh java", 70, "Vu Thi Duong"},
				{"Tri tue nhan tao", 80, "Nguyen Lan Anh"},
				{"Tieng Anh CNTT", 90, "Nguyen Thi Minh"},
				{"Xac suat thong ke", 100, "Nguyen Dao Son"}
};

int searchCost(int l, int r)
{
	if(l == r)
	{
		if(d[l].cost < 100)
		{
			cout<<"Thong tin:\t"<<"Ten: "<<d[l].nameBook<<"\tGia bia: ";
			cout<<d[l].cost<<"\tTen TG: "<<d[l].nameAuthor<<endl;
			return 1;
		}
		else return 0;
	}
	else
	{
		int m = (l + r)/ 2;
		return searchCost(l, m) + searchCost(m+1, r);
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
		if(Boyer_Moore_Horspool(d[i].nameAuthor, "Anh") != 0)
			count ++;
	if(count == 0)
		cout << "\n\"Anh\" khong xuat hien trong d.";
	else{
		cout << "\n\"Anh\" xuat hien " << count << " lan trong d.\n";
		for(int i = 0; i < n; i++)
			if(Boyer_Moore_Horspool(d[i].nameAuthor, "Anh") != 0){
				cout  << d[i].nameBook << "\t" << d[i].cost << "\t" << d[i].nameAuthor << endl;
			}
	}
}

main(){
	cout<<"\nSo luong giao trinh co gia bia < 100: "<<searchCost(0, n-1)<<endl;
	count();
}
