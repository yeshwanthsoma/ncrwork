#include<stdio.h>
#include<string.h>
int main() {
	char st[10],flag=0;
	int len,i;
	printf("Enter a string\n");
	gets(st);
	len = strlen(st);
	for (i = 0; i <(len) / 2; i++) {
		if (st[i] != st[ len - 1-i]) {
			flag = 1;
			break;
		}
		}

	if (flag == 0) {
		printf("palindrome");
	}
	else
		printf("not palindrome");
	return 0;
}