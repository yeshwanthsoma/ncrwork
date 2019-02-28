#include<Windows.h>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
	CHAR ch[10];//creating a char type	
	WCHAR ch2[10];//creating a unicode type
	BOOL p;
	cout << "enter the ASCII ";
	cin >> ch;
	int a;
	a = MultiByteToWideChar(CP_UTF8, 0, ch, -1, NULL, 0);
	cout << endl<<"the unicode is:";
	a = MultiByteToWideChar(CP_UTF8, 0, ch, -1, ch2, a);
	wcout << ch2;
	cin >> p;

}