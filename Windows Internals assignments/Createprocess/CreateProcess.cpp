using namespace std;
#include<Windows.h>
#include<iostream>
#include<tchar.h>

int _tmain(int argv,TCHAR* argc[],WCHAR *env[]) {
	STARTUPINFO SCALC,SNOTE;
	PROCESS_INFORMATION PCALC,PNOTE;
	BOOL res,res1;
	ZeroMemory(&SCALC,sizeof(SCALC));
	ZeroMemory(&PCALC, sizeof(PCALC));
	ZeroMemory(&SNOTE, sizeof(SNOTE));
	ZeroMemory(&PNOTE, sizeof(PNOTE));

	res = CreateProcess(NULL,
		argc[1],
						NULL,
						NULL,
						FALSE,
		NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&SCALC,
		&PCALC

	);
	if (res == 0) {
		printf("No the process is not created");
}
	else {
		printf("Yes the calc process will be opened");
		printf("\n the process id is %d", PCALC.dwProcessId);
	}

	res1 = CreateProcess(NULL,
		argc[2],
		NULL,
		NULL,
		FALSE,
		NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&SNOTE,
		&PNOTE

	);
	if (res1 == 0) {
		printf("No the process is not created");
	}
	else {
		printf("Yes the note process will be opened");
		printf("\n the process id is %d", PNOTE.dwProcessId);
	}

	int m;
	cin >> m;
}