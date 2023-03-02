#include <iostream>
#include <iomanip>

using namespace std;

//Dinh nghia 1 struct the hien nuoc di cua quan ma
struct Move{
	int v;
	int h;
};
//Khai bao 1 mang gom cac nuoc di co the co cua quan ma
Move m[8] = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
//Kich thuoc ban co
int n;
//Mang 2 chieu the hien cac o tren ban co
int **b;
//Ham tim duong di cho quan ma
void track(int k, int x, int y, int &done){
	int u, v, d, i = -1;
	do{
		i ++;
		d = 0;
		u = x + m[i].v;
		v = y + m[i].h;
		if(u >= 0 && u < n && v >= 0 && v < n && b[u][v] == 0){
			b[u][v] = k;
			if(k < n*n){
				track(k+1,u,v,d);
				if(!d)
					b[u][v] = 0;
			}
			else
				d = 1;	
		}
	} while(!d && i < 7);
	done = d;
}
//Ham nhap kich thuoc ban co
void enterSize(){
	do{
		cout << "Nhap kich thuoc ban co (n x n, 3 <= n <= 8) n = ";
		cin >> n;
		if(n < 3 || n > 8)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 3 || n > 8);
}
//Ham khoi tao ban co
void createBoard(){
	b = new int*[n];
	for(int i = 0; i < n; i++)
		b[i] = new int[n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			b[i][j] = 0;
}
//Ham khoi tao buoc di dau tien
void firstMove(int &x, int &y){
	do{
		cout << "Nhap toa do vi tri dau tien cua quan ma.\n";
		cout << "x (1 <= x <= " << n << ") = ";
		cin >> x;
		cout << "y (1 <= y <= " << n << ") = ";
		cin >> y;
		if(x <= 0 || x > n || y <= 0 || y > n)
			cout << "Nhap sai. Nhap lai!\n";
	} while(x <= 0 || x > n || y <= 0 || y > n);
	b[--x][--y] = 1;
}
//Ham hien thi ket qua
void displayResult(int d){
	if(d){
		cout << "Duong di cua quan ma:\n\n";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << setw(4) << b[i][j];
			cout << endl;
		}		
	}
	else
		cout << "Khong co duong di nao!\n";
}

int main(){
	int x, y, d;
	enterSize();
	createBoard();
	firstMove(x,y);
	track(2,x,y,d);
	displayResult(d);
}
