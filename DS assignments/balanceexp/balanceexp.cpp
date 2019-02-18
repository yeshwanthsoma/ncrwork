using namespace std;
#include<iostream>
#include<string>
#include<stack>

int main() {
	int b, c, i;
	string st;
	getline(cin, st);
	for (i = 0; st[i] != '\0'; i++);
	int count = i;
	stack <char> a;
	for (i = 0; i < count; i++) {
		if (st[i] == '{' || st[i] == '(' || st[i] == '[') {
			a.push(st[i]);
			}
		if (st[i] == ')') {
			if (a.top() == '(') {
				a.pop();
			}
			else
				break;
		}
		if (st[i] == ']') {
			if (a.top() == '[') {
				a.pop();
			}
			else
				break;
		}
		if (st[i] == '}') {
			if (a.top() == '{') {
				a.pop();
			}
			else
				break;
		}
	
	}
	if (!a.empty())
		cout << "not valid";
	else
		cout << "valid exp";
	
	return 0;
	a.
}