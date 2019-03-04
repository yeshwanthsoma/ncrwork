using namespace std;
#include<Windows.h>
#include<iostream>
int glo;
DWORD WINAPI func(LPVOID LP) {
	glo++;
	return 0;
}

int main() {
	HANDLE res[1];
	DWORD t1, t2;
	while (1) {
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

	WaitForMultipleObjects(2,res,1,INFINITE);
	cout << "THE glo val is" << glo << endl;
	if (glo != 2) {
		cout << " the threads are inconsistent";
		break;
	}
	

	


}

	int a;
	cin >> a;
	CloseHandle(res[0]);
	CloseHandle(res[1]);
}