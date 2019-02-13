#include<stdio.h>
#include<math.h> 
int main()
{
	int a,b,c,d=0;
	long int bin=0,dec=0;
	int hex;
	printf("enter the input\n");
	printf("1. Binary to hexadecimal\n");
	printf("2.hexadecimal to binary\n");
	scanf_s("%d", &a);
	if (a == 1){
		printf("enter binary number:");
		scanf_s("%ld", &bin);
		while (bin > 0) {
			c = bin % 10;
			dec = dec + (c*pow(2, d));
			bin = bin / 10;
			d++;
		}
		printf("\n%x\n", dec);
	}
	else {
		printf("enter hexadecimal:");
		scanf_s("%x",&hex);
		dec = (int)hex;
		while (dec > 0) {
			c = dec % 2;
			bin = bin + (c*(pow(10, d)));
			dec = dec / 2;
			d++;
		}
		printf("the binary num is %ld\n", bin);
	}
	return 0;
}