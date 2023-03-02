#include <iostream>
#include <queue>

using namespace std;

struct Task{
	int i;
	float s, f;
};

void input(Task *&t, int &n){
	do{
		cout << "Nhap so luong cong viec: ";
		cin >> n;
		if(n < 1)
			cout << "Nhap sai. Nhap lai!\n";
	} while(n < 1);
	t = new Task[n];
	for(int i=0; i<n; i++){
		cout << "CONG VIEC THU " << i+1 << endl;
		t[i].i = i + 1;
		do{
			cout << "Nhap thoi diem bat dau (>= 0): ";
			cin >> t[i].s;
			if(t[i].s < 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(t[i].s < 0);
		do{
			cout << "Nhap thoi diem ket thuc (>= 0): ";
			cin >> t[i].f;
			if(t[i].f < 0)
				cout << "Nhap sai. Nhap lai!\n";
		} while(t[i].f < 0);
	}
}

void sort(Task *t, queue<Task> &l, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(t[i].f > t[j].f)
				swap(t[i], t[j]);
	for(int i=0; i<n; i++)
		l.push(t[i]);
}

void scheduling(queue<Task> l){
	queue<int> s;
	float lastf = l.front().f;
	s.push(l.front().i);
	l.pop();
	while(l.size() != 0){
		if(l.front().s >= lastf){
			s.push(l.front().i);
			lastf = l.front().f;
		}
		l.pop();
	}
	cout << "Lich: ";
	while(s.size() != 0){
		cout << s.front() << " ";
		s.pop();
	}
}

int main(){
	int n;
	Task *t;
	queue<Task> l;
	input(t,n);
	sort(t,l,n);
	scheduling(l);
}
