#include<stdio.h>
#include<math.h>
int main() {
	int a, b, c,res=0;
	printf("Enter the number");
	scanf_s("%d", &a);
	b = a;
	while(b > 0) {
		c = b % 10;
		res = (res * 10) + c;
		b = b / 10;
	}
	printf("%d", res);
}