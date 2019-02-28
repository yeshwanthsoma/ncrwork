#include<Windows.h>
#include<iostream>
#include<string.h>
using namespace std;
int main() {
	CHAR ch[10];//creating a char type	
	WCHAR ch2[10];//creating a unicode type
	BOOL p;
	cout << "enter the UNICODE ";
	wcin >> ch2;
	int a;
	a = WideCharToMultiByte(CP_UTF8, 0, ch2, -1, NULL, 0,NULL,NULL);
	cout << endl << "the asci is:";
	a = WideCharToMultiByte(CP_UTF8, 0, ch2, -1, ch, a,NULL,NULL);
	wcout << ch2;
	cin >> p;

}