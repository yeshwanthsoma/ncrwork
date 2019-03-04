using namespace std;
#include<Windows.h>
#include<iostream>
DWORD WINAPI func(LPVOID LP) {
	printf("This function is called by thread");
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
	//WaitForSingleObject(res, INFINITE);
	cout <<"THE THREAD ID IS " <<t<<endl;
	int a;
	cin >> a;
	CloseHandle(res);
}