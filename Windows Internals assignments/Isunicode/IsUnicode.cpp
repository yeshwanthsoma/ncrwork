#include<Windows.h>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
	CHAR ch = 'A';//creating a char type	
	WCHAR ch2[10] ;//creating a unicode type
	BOOL p;
	cout << "enter the unicode  ";
	wcin >> ch2;
	wcout << endl<<"the string ch2 is :  " << ch2 << endl;
	p = IsTextUnicode(ch2, wcslen(ch2), NULL);
	if (p == 1) {
		cout << "ch2 is a UNICODE";
	}
	else {
		cout << "It is not a UNICODE";
	}

	cin >> p;
	
}