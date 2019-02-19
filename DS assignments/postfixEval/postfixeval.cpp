using namespace std;
#include<iostream>
#include<stack>
#include<string>
int main() {
	int  i,p,c1,c2;
	stack <int> a;
	string st;
	getline(cin, st);
	for (i = 0; st[i] != '\0'; i++);
	int count = i;
	for (i = 0; i < count; i++) {
		switch (st[i]) {
		case '+':c1 =a.top();
				a.pop();
			c2 = a.top(); a.pop();
			a.push(c2 + c1); break;
		case '-':c1 = a.top(); a.pop();
			c2 = a.top(); a.pop();
			a.push(c2 - c1); break;
		case '*':c1 = a.top(); a.pop();
			c2 = a.top(); a.pop();
			a.push(c2 * c1); break;
		case '/':c1 = a.top(); a.pop();
			c2 = a.top(); a.pop();
			a.push(c2 / c1); break;
				
		default:p = st[i] - '0';
			a.push(p);
		}
	}
	cout << a.top();
	cin >> i;


}