#include <iostream>
#include <stack>

using namespace std;

//Delcare a struct representing a command that execute one transportation
//(Khai bao 1 struct dai dien cho 1 cau lenh ma se thuc hien 1 lan chuyen)
struct Command{
	int n;
	char source;
	char temp;
	char target;
};

//Declare a stack containing commands
//(Khai bao 1 ngan xep chua cac cau lenh)
stack<Command> Stack;

//Non-recursive function solving Hanoi Tower problem
//(Ham khong de quy giai quyet bai toan Thap Ha Noi)
void haNoiTower(Command first_call){
	Command c;
	Stack.push(first_call);
	while(!Stack.empty()){
		c = Stack.top();
		Stack.pop();
		if(c.n == 1)
			cout << "Move a disk from '" << c.source << "' ==> '" << c.target << "'\n";
		else{
			Command x, y, z;
			x.n = c.n - 1; x.source = c.source; x.temp = c.target; x.target = c.temp;
			y = c; y.n = 1;
			z.n = c.n - 1; z.source = c.temp; z.temp = c.source; z.target = c.target;
			Stack.push(z);
			Stack.push(y);
			Stack.push(x);
		}
	}
}

//Function creating the first command
//(Ham tao cau lenh dau tien)
void createFirstCall(Command &c){
	cout << "Enter the number of disks (Nhap so luong dia): ";
	cin >> c.n;
	cout << "Enter the name of 3 rods in order (Nhap ten cua 3 coc theo thu tu):\n";
	cin >> c.source >> c.temp >> c.target;
}

int main(){
	Command c;
	createFirstCall(c);
	haNoiTower(c);
}
