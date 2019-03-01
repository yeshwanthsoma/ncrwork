using namespace std;
#include<Windows.h>
#include<iostream>
#include<tchar.h>

int _tmain(int argv,TCHAR *argc[],WCHAR *env[]) {

	BOOL res;
	STARTUPINFO SCALC;
	PROCESS_INFORMATION PCALC;
	ZeroMemory(&SCALC, sizeof(SCALC));
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

	int p=GetCurrentProcessId();
	cout << "the current process id is "<<p<<endl;
	cout << "the current thread id is "<<GetCurrentThreadId<<endl;
	cout << "the process id is " << GetProcessId(PCALC.hProcess)<<endl;
	cout << "the thread id is " << GetThreadId(PCALC.hThread) << endl;
	int a;
	cin >> a;

}