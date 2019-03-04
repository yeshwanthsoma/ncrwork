using namespace std;
#include<Windows.h>
#include<iostream>
DWORD WINAPI func(LPVOID LP) {
	
	for (int i = 0; i < 1000; i++)
		cout << i<<endl;
	return 0;
}
int main() {
	HANDLE res;
	DWORD t;
	res = CreateThread(NULL,//security attributes
		0,//size 
		func,//call back func
		NULL,//parameters passing
		CREATE_SUSPENDED,//flag
		&t//thread id receiver
	);
	Sleep(5000);
	ResumeThread(res);
	WaitForSingleObject(res, INFINITE);
	cout << "THE THREAD ID IS " << t << endl;
	int a;
	cin >> a;
	CloseHandle(res);
}