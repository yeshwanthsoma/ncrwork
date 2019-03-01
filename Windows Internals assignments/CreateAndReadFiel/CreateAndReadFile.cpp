using namespace std;
#include<windows.h>
#include<string>
#include<iostream>
#include<tchar.h>
#define max 100
int main() {
	HANDLE hfile;
	//TCHAR size;
	DWORD size=0;
	BOOL res;
	TCHAR tfile[] = {(TEXT("hello.txt.txt"))},out[max];
	ZeroMemory(out, max);
	hfile = CreateFile(tfile, 
					   GENERIC_READ,
						0,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL		
						);

	if (hfile == INVALID_HANDLE_VALUE) {
		cout << "failed to return handler ";
		cout << GetLastError();
}
	else {
		//cout << "yes";
		res = ReadFile(hfile,
						out,
						max+1,
						&size,
						NULL		
						);
		//cout << size;

			_tprintf(_T("%S\n"), out);

	}
	int p;
	cin >> p;
}