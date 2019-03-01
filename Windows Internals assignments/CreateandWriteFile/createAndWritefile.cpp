using namespace std;
#include<windows.h>
#include<string>
#include<iostream>
#include<tchar.h>
#define max 100
int main() {
	HANDLE hfile;
	//TCHAR size;
	DWORD size = 0;
	BOOL res;
	TCHAR tfile[] = { (TEXT("NEW.txt")) }, out[max]={(TEXT("NEW DATA"))};
	//ZeroMemory(out, max);
	hfile = CreateFile(tfile,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hfile == INVALID_HANDLE_VALUE) {
		cout << "failed to return handler ";
		cout << GetLastError();
	}
	else {
		//cout << "yes";
		res = WriteFile(hfile,
			out,
			sizeof(TCHAR)*(wcslen(out)+1),
			&size,
			NULL
		);
		//cout << size;

		_tprintf(_T("%s\n"), out);

	}
	int p;
	cin >> p;
}