using namespace std;
#include<Windows.h>
#include<iostream>
int p;
DWORD WINAPI func(LPVOID LP) {
	printf("This function is called by thread");
	ExitThread(p);
	return 0;
}
int main() {
	HANDLE res;
	DWORD t;
	
	res = CreateThread(NULL,//security attributes
		0,//size 
		func,//call back func
		NULL,//parameters passing
		0,//flag
		&t//thread id receiver
	);
	GetExitCodeThread(res, (LPDWORD)&p);
	WaitForSingleObject(res, INFINITE);
	
	cout << "THE THREAD ID IS " << t << endl;
	int a;
	cin >> a;
	CloseHandle(res);
}