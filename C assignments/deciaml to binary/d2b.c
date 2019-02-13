#include<stdio.h>
#include<math.h>

void main() {
	int a, c;
	double d = 0;
	long int bin = 0, dec = 0;
	printf("enter the input : \n");
	printf("1. binary to decimal\n");
	printf("2. decimal to binary\n");
	scanf_s("%d", &a);
	if (a == 1)
	{
		printf("enter binary num:");
		scanf_s("%ld", &bin);
		while (bin > 0) {
			c = bin % 10;
			if (c>1)
			{
				printf("invalid\n");
				goto x;
			}
			dec = dec + (c*pow(2, d));
			bin = bin / 10;
			d++;
		}
		printf("the decimal num is %ld\n", dec);

	}
	else
	{
		printf("enter decimal num:");
		scanf_s("%ld", &dec);
		while (dec > 0) {
			c = dec % 2;
			bin = bin + (c*(pow(10, d)));
			dec = dec / 2;
			d++;
		}
		printf("the binary num is %ld\n", bin);
	}
x:
	getch();
}