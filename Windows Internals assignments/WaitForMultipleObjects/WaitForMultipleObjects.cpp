using namespace std;
#include<Windows.h>
#include<iostream>
DWORD WINAPI func1(LPVOID LP) {
	Sleep(4000);
	printf("This function is called by thread1\n");
	return 0;
}
DWORD WINAPI func2(LPVOID LP) {
	Sleep(3000);
	printf("This function is called by thread2\n");
	return 0;
}
int main() {
	HANDLE res[1];
	DWORD t;
	cout << "Select option";
	cout << "1.INFINITE  2.INFINITE T1-4000 & T2-3000  3.INFINITE T1-2000 & T2-3000  4.2000 T1-4000 & T2-3000" << endl;
	int p;
	cin >> p;

	res[0] = CreateThread(NULL,//security attributes
		0,//size 
		func1,//call back func
		NULL,//parameters passing
		0,//flag
		&t//thread id receiver
	);
	res[1] = CreateThread(NULL,//security attributes
		0,//size 
		func2,//call back func
		NULL,//parameters passing
		0,//flag
		&t//thread id receiver
	);


	switch (p) {
	case 1: cout << endl << WaitForMultipleObjects(2, res, 1, INFINITE) << endl;
		break;
	case 2: cout << endl << WaitForMultipleObjects(2, res, 1, 2000) << endl;
		break;

	}

	cout << "THE THREAD ID IS " << t << endl;
	int a;
	cin >> a;
	CloseHandle(res);
}