#include<stdio.h>
int main() {
	int a, b=0, c,num;
	printf("Enter the number\n");
	scanf_s("%d", &num);
	while (num > 0) {
		a = num % 10;
		b = b + a;
		num = num / 10;
	}
	printf("The sum is %d", b);
}