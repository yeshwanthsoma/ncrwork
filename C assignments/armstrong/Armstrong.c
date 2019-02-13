#include<stdio.h>

int main()
{
	int n,t,sum=0;
	scanf_s("%d",&t);
	n=t;
	//int sum = 0;
	while (n > 0) {
		sum = sum + (n % 10)*(n % 10)*(n%10);
		n /= 10;
	}
	if (sum == t)
		printf("armstrong");
	else
		printf("not");
	getch();
	return 0;

}