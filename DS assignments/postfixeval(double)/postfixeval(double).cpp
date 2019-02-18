using namespace std;
#include<iostream>
#include<stack>
#include<string>
#include<math.h>
int main() {
	int  i, p=0, c1, c2,c,d;
	stack <int> a;
	string st;
	getline(cin, st);
	for (i = 0; st[i] != '\0'; i++);
	int count = i;
	for (i = 0; i < count; i++) {
		switch (st[i]) {
		case '+':c1 = a.top();
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
		case '@':	break;
		default:	d = 0; p = 0;
			while (st[i] != '@') {

				c = st[i] - '0';
				p = c + p* pow(10,d);
				d++; i++;
			}
			a.push(p);
		}
	}
	cout << a.top();
	cin >> i;


}