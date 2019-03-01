using namespace std;
#include<Windows.h>
#include<iostream>
#include<tchar.h>

int _tmain(int argv,TCHAR* argc[],WCHAR *env[]) {
	STARTUPINFO SCALC;
	PROCESS_INFORMATION PCALC;
	BOOL res;
	ZeroMemory(&SCALC,sizeof(SCALC));
	ZeroMemory(&PCALC, sizeof(PCALC));

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
		printf("No");
}
	else {
		printf("Yes");
	}
	int m;
	cin >> m;
}