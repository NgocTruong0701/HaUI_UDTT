#include <iostream>

using namespace std;

//Recursive function solving Hanoi Tower problem
//(Ham de quy giai quyet bai toan Thap Ha Noi)
void haNoiTower(char source, char temp, char target, int n){
	if(n == 1)
		cout << "Move a disk from '" << source << "' ==> '" << target << "'\n";
	else{
		haNoiTower(source, target, temp, n-1);
		haNoiTower(source, temp, target, 1);
		haNoiTower(temp, source, target, n-1);
	}
}

int main(){
	haNoiTower('a', 'b', 'c', 3);
}
