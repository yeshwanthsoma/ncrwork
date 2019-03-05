using namespace std;
#include<Windows.h>
#include<iostream>
long glo; CRITICAL_SECTION sec;
DWORD WINAPI func(LPVOID LP) {
	EnterCriticalSection(&sec);
	glo++;
	LeaveCriticalSection(&sec);
	return 0;

}

int main() {
	HANDLE res[1]; int p = 0, flag = 0;
	DWORD t1, t2;
	
	InitializeCriticalSectionAndSpinCount(&sec,2000);
	while (p <= 2000) {
		glo = 0;
		res[0] = CreateThread(NULL,//security attributes
			0,//size 
			func,//call back func
			NULL,//parameters passing
			0,//flag
			&t1//thread id receiver
		);
		res[1] = CreateThread(NULL,//security attributes
			0,//size 
			func,//call back func
			NULL,//parameters passing
			0,//flag
			&t2//thread id receiver
		);

		WaitForMultipleObjects(2, res, 1, INFINITE);
		cout << "THE glo val is" << glo << endl;
		if (glo != 2) {
			cout << " the threads are inconsistent";
			break; flag = 1;
		}

		p++;



	}
	DeleteCriticalSection(&sec);
	cout << "Critical section deleted"<<endl;
	if (flag == 0) {
		cout << "The threads are consistent";
	}

	int a;
	cin >> a;
	CloseHandle(res[0]);
	CloseHandle(res[1]);
}