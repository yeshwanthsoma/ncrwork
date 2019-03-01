#include<Windows.h>
#include<stdio.h>
int main() {
	LPWSTR *argc;
	int i, length,m;
	argc = CommandLineToArgvW(GetCommandLineW(), &length);
	if (NULL == argc) {
		wprintf(L"The commandline return failed");
	}
	else {
		for (i = 0; i < length; i++) {
			printf(" %d %ws \n", i,argc[i]);
		}
	}
	scanf_s("%d", &m);
}