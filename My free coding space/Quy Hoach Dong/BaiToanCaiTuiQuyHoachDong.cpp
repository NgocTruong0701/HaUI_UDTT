#include <iostream>
#include <iomanip>

using namespace std;

//Dinh nghia mot goi hang
struct Package{
	int w; //Can nang
	int v; //Gia tri
};

Package p[6] = {{2,2}, {1,3}, {3,1}, {5,3}, {2,4}, {3,5}};

int n = 6;

void input(int &m, int **&F){
	do{
		cout << "Nhap khoi luong toi da ma tui chua duoc: ";
		cin >> m;
		if(m <= 0)
			cout << "Nhap sai. Nhap lai!\n";
	} while(m <= 0);
	F = new int*[n + 1];
	for(int i = 0; i <= n; i++)
		F[i] = new int[m + 1];
}

//Ham quy hoach dong
void bag(int m, int **F){
	int temp;
	for(int i = 0; i <= m; i++)
		F[0][i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			F[i][j] = F[i - 1][j];
			temp = F[i - 1][j - p[i - 1].w] + p[i - 1].v;
			if(p[i - 1].w <= j && F[i][j] < temp)
					F[i][j] = temp;
		}
}

//void table(int m, int **F){
//	for(int i = 0; i <= n; i++){
//		for(int j = 0; j <= m; j++)
//			cout << setw(5) << F[i][j];
//		cout << endl;
//	}
//}

//Ham in ra ket qua
void output(int m, int **F){
	cout << "\nLay duoc gia tri lon nhat la: " << F[n][m];
	cout << "\nCac goi duoc lay la:\n";
	int i = n, j = m;
	while(i){
		if(F[i][j] != F[i - 1][j]){
			cout << "- Goi " << i << " (" << p[i - 1].w << "," << p[i - 1].v << ")\n";
			j -= p[i - 1].w;
		}
		i --;
	}
}

int main(){
	int m;
	int **F;
	input(m,F);
	bag(m,F);
//	table(m,F);
	output(m,F);
}
