#include<stdio.h>

void main() {

	int a, b, num,count=0;
	long int bin;
	printf("Enter the number\n");
	scanf_s("%d", &num);
	while (num > 0) {
		b = num % 2;
		if (b == 1)
			count++;
		num = num / 2;
	}
	printf("No of 1's are %d\n", count);


}