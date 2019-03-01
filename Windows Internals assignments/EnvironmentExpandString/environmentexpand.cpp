using namespace std;
#include<Windows.h>
#include<tchar.h>
#include<iostream>
#include<string.h>
int _tmain(int argc,TCHAR* argv[],WCHAR *env[]) {
	TCHAR a,P[10];
	DWORD size=wcslen(argv[1]+1);
	int q;
	a = ExpandEnvironmentStrings(argv[1], P, size);
	_tprintf(_T("%s"), P);
	cin >> q;
}