using namespace std;
#include<Windows.h>
#include<iostream>
#include<tchar.h>

int _tmain(int argv,TCHAR *argc[],WCHAR *env[]) {
	HANDLE event1;
	SECURITY_ATTRIBUTES sec;
	sec.bInheritHandle = TRUE;
	sec.nLength = 0;
	sec.lpSecurityDescriptor = NULL;
	BOOL res;
	STARTUPINFO SCALC;
	PROCESS_INFORMATION PCALC;
	ZeroMemory(&SCALC, sizeof(SCALC));
	ZeroMemory(&PCALC, sizeof(PCALC));
	event1 = CreateEvent(&sec,
		FALSE,
		TRUE,
		TEXT("the first event")

	);
	if (event1 != NULL)
		cout << "event handler is created";
	else
		cout << "event handler is not created";
	res = CreateProcess(NULL,
					argc[1],
					&sec,
					NULL,
					TRUE,
		NORMAL_PRIORITY_CLASS,
			NULL,
			NULL,
			&SCALC,
			&PCALC

			);
	if (res == 1) {
		cout << "process is created";
	}
	else {
		cout << "process is not created";
	}
	int a;
	cin >> a;

}