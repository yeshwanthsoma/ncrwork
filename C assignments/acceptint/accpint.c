#include<stdio.h>
int main() {
	int a[20], i, c=0,sum=0,min=100000,max=-2;
	for (i = 0; i < 20; i++) {
		scanf_s("%d", &a[i]);
		c++;
		if (a[i] <= 0) {
			break;
		}
		sum = sum + a[i];
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];

	}
	printf("The no of pos int is %d\n", c - 1);
	printf("min is %d\n", min);
		printf("max is %d\n", max);
		printf("sum is %d", sum);


}