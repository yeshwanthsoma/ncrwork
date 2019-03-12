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
	stack <char> ca;
	for (i = 0; i < count; i++) {
		if (st[i] == '{' || st[i] == '(' || st[i] == '[') {
			ca.push(st[i]);
			}
		if (st[i] == ')') {
			if (ca.top() == '(') {
				ca.pop();
			}
			else
				break;
		}
		if (st[i] == ']') {
			if (ca.top() == '[') {
				ca.pop();
			}
			else
				break;
		}
		if (st[i] == '}') {
			if (ca.top() == '{') {
				ca.pop();
			}
			else
				break;
		}
	
	}
	if (!ca.empty())
		cout << "not valid";
	else
		cout << "valid exp";
	int z;
	cin >> z;
	return 0;
	
}