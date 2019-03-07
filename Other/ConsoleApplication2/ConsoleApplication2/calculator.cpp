using namespace std;
#include<iostream>
#include<string>
#include<stack>
int checkpre(char);
stack<char> a;
int main() {
	string st;

	char out[20];
	int i, p = 0;
	cout << "Enter the expression" << endl;
	getline(cin, st);
	for (i = 0; st[i] != '\0'; i++);
	int count = i;
	//cout << count<<st[2];

	for (i = 0; i < count; i++) {
		switch (st[i]) {
		case '+':
		case '-':
		case '*':
		case '/':	if (a.empty()) {
			a.push(st[i]);
		}
					else {
						if (checkpre(st[i]) > 0) {

							a.push(st[i]);
						}
						else {
							out[p] = a.top();
							a.pop();
							p++;
							a.push(st[i]);
						}
					}break;
		case '[':
		case '(':
			a.push(st[i]);
			break;
		case ']':while (a.top() != '[') {
			out[p] = a.top();
			a.pop();
			p++;
		}
				 a.pop();
				 break;
		case ')':
			while (a.top() != '(') {
				out[p] = a.top();
				a.pop();
				p++;
			}
			a.pop();
			break;

		default: out[p] = st[i];
			p++;
		}
	}
	while (!a.empty()) {
		out[p] = a.top();
		p++;
		a.pop();
	}
	//for (i = 0; i < p; i++) {
		//cout << out[i];
	//}

	
		float   c1, c2;
		int c, d;
		stack <float> b;
		int len = p;
		for (i = 0; out[i] != '\0'; i++);
			count = i;
		for (i = 0; i < len; i++) {
			switch (out[i]) {
			case '+':c1 =b.top();
				b.pop();
				c2 = b.top(); b.pop();
				b.push(c2 + c1); break;
			case '-':c1 = b.top(); b.pop();
				c2 = b.top(); b.pop();
				b.push(c2 - c1); break;
			case '*':c1 = b.top(); b.pop();
				c2 = b.top(); b.pop();
				b.push(c2 * c1); break;
			case '/':c1 = b.top(); b.pop();
				c2 = b.top(); b.pop();
				b.push(c2 / c1); break;

			case '@':	break;
			default:	d = 0; p = 0;
				while (out[i] != '@') {

					c = out[i] - '0';
					p = c + p* pow(10, d);
					d++; i++;
				}
				b.push(p);
			}
		}
		cout << b.top();










	cin >> i;
	return 0;
	
	



}
int checkpre(char b) {
	int p = 0;
	switch (b) {
	case '+':
	case '-':p = 1; break;
	case '*':
	case '/':p = 2; break;

	}
	switch (a.top()) {
	case '+':
	case '-':p = p - 1; return p;
	case '*':
	case '/':p = p - 4; return p;
	case '(':
	case '[':		return 1;
	}

}