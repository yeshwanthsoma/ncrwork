using namespace std;
#include<Windows.h>
#include<iostream>
DWORD WINAPI func(LPVOID LP) {
	Sleep(2000);
	printf("This function is called by thread");
	return 0;
}
int main() {
	HANDLE res;
	DWORD t;
	cout << "Select option";
	cout << "1.INFINITE  2.1000 & sleep" << endl;
	int p;
	cin >> p;

	res = CreateThread(NULL,//security attributes
		0,//size 
		func,//call back func
		NULL,//parameters passing
		0,//flag
		&t//thread id receiver
	);
	switch(p){
	case 1: WaitForSingleObject(res, INFINITE);
			break;
	case 2: WaitForSingleObject(res, 1000);
			break;
	
	}
	
	cout << "THE THREAD ID IS " << t << endl;
	int a;
	cin >> a;
	CloseHandle(res);
}