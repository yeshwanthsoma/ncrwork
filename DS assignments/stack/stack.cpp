using namespace std;
#include<iostream>

struct stack {
	int size;
	int *s;
	int top;
};

class stac {
	stack a;
public:
	void push(int n);
	int pop();
	bool Isemp();
	bool Isfull();
	void display();
	void getsize(int n);
	stac();
};

stac::stac() {
	a.size = 0;
	a.s = NULL;
	a.top = -1;
}

void stac::getsize(int n) {
	a.s = new int[n];
	a.size = n;
}
void stac::push(int n) {
	if (!Isfull())
	a.s[++a.top] = n;

}

bool stac::Isemp() {
	return(a.top == -1);
}
bool stac::Isfull() {
	return(a.top==(a.size-1) );
}
int stac:: pop() {
	if (!Isemp()) {
		return(a.s[a.top--]);
	}
}
void stac::display() {
	int i;
	cout << "the elements are:" << endl;
	for (i = 0; i <= a.top; i++) {
		cout << a.s[i] << endl;
	}
}
int main() {
	stac st;
	int a,b,i;

	cout << "Enter the size of stack";
	cin >> a;
	st.getsize(a);
	while(1){
	cout << "1.push" << endl << "2.pop" << endl << "3.display" << endl<<"4.exit"<<endl;
	cin >> b;
	
		switch (b) {
		case 1: cout << "enter the integer";
			cin >> i;
			st.push(i);
			break;
		case 2: i = st.pop();
			cout << "you have popped " << i << endl;
			break;
		case 3: st.display();
			break;
		case 4: exit(1);
		default:;
		}
	}

}

