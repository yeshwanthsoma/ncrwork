using namespace std;
#include<Windows.h>
#include<iostream>
#include<queue>
int glo; SRWLOCK lockR, lockW;
CONDITION_VARIABLE conR, conW;
queue <int> que;
DWORD WINAPI Rfunc1(LPVOID LP) {
	AcquireSRWLockExclusive(&lockR);
	if (que.empty())
		SleepConditionVariableSRW(&conR, &lockR, INFINITE,0);
	else {
		int p = que.front();
		cout << "readvalue " << p << endl;
		que.pop();
		WakeConditionVariable(&conW);
	}
	ReleaseSRWLockExclusive(&lockR);
	return 0;

}
DWORD WINAPI Rfunc2(LPVOID LP) {
	AcquireSRWLockExclusive(&lockR);
	if (que.empty())
		SleepConditionVariableSRW(&conR, &lockR, INFINITE, 0);
	else {
		cout << "readvalue " << que.front() << endl;
		que.pop();
		WakeConditionVariable(&conW);
	}
	ReleaseSRWLockExclusive(&lockR);
	return 0;
}
DWORD WINAPI Wfunc1(LPVOID LP) {
	AcquireSRWLockExclusive(&lockW);
	if (que.size() == 5)
		SleepConditionVariableSRW(&conW, &lockW, INFINITE, 0);
	else {
		que.push(1);
		cout << "valueincremented" << endl;
		WakeAllConditionVariable(&conR);

	}
	ReleaseSRWLockExclusive(&lockW);
	return 0;
}
DWORD WINAPI Wfunc2(LPVOID LP) {
	AcquireSRWLockExclusive(&lockW);
	if (que.size() == 5)
		SleepConditionVariableSRW(&conW, &lockW, INFINITE, 0);
	else {
		que.push(2);
		cout << "valueincremented" << endl;
		WakeAllConditionVariable(&conR);

	}
	ReleaseSRWLockExclusive(&lockW);
	return 0;
}
DWORD WINAPI Wfunc3(LPVOID LP) {
	AcquireSRWLockExclusive(&lockW);
	if (que.size() == 5)
		SleepConditionVariableSRW(&conW, &lockW, INFINITE, 0);
	else {
		que.push(3);
		cout << "valueincremented" << endl;
		WakeAllConditionVariable(&conR);

	}
	ReleaseSRWLockExclusive(&lockW);
	return 0;
}
DWORD WINAPI Wfunc4(LPVOID LP) {
	AcquireSRWLockExclusive(&lockW);
	if (que.size() == 5)
		SleepConditionVariableSRW(&conW, &lockW, INFINITE, 0);
	else {
		que.push(4);
		cout << "valueincremented" << endl;
		WakeAllConditionVariable(&conR);

	}
	ReleaseSRWLockExclusive(&lockW);
	return 0;
}

int main() {
	HANDLE read[1], write[3], array[5];
	array[0] = read[0];
	array[1] = read[1];
	for (int i = 2; i < 6; i++)
		array[i] = write[i - 2];
	DWORD Rt1, Rt2, Wt1, Wt2, Wt3, Wt4;

	InitializeSRWLock(&lockR);
	InitializeSRWLock(&lockW);
	InitializeConditionVariable(&conR);
	InitializeConditionVariable(&conW);
	while (1) {
		glo = 0;
		read[0] = CreateThread(NULL,//security attributes
			0,//size 
			Rfunc1,//call back func
			NULL,//parameters passing
			0,//flag
			&Rt1//thread id receiver
		);
		read[1] = CreateThread(NULL,//security attributes
			0,//size 
			Rfunc2,//call back func
			NULL,//parameters passing
			0,//flag
			&Rt2//thread id receiver
		);
		write[0] = CreateThread(NULL,//security attributes
			0,//size 
			Wfunc1,//call back func
			NULL,//parameters passing
			0,//flag
			&Wt1//thread id receiver
		);
		write[1] = CreateThread(NULL,//security attributes
			0,//size 
			Wfunc2,//call back func
			NULL,//parameters passing
			0,//flag
			&Wt2//thread id receiver
		);
		write[2] = CreateThread(NULL,//security attributes
			0,//size 
			Wfunc3,//call back func
			NULL,//parameters passing
			0,//flag
			&Wt3//thread id receiver
		);
		write[3] = CreateThread(NULL,//security attributes
			0,//size 
			Wfunc4,//call back func
			NULL,//parameters passing
			0,//flag
			&Wt4//thread id receiver
		);

		WaitForMultipleObjects(6, array, 1, INFINITE);
		/*cout << "THE glo val is" << glo << endl;
		if (glo != 2) {
		cout << " the threads are inconsistent";
		break;
		}*/





	}

	int a;
	cin >> a;
	//CloseHandle(res[0]);
	//CloseHandle(res[1]);
}