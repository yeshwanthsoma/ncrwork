#include<stdio.h>

int main() {
	int arr[10],a=0,b,c,size,sum,i,j;
	printf("enter the size");
		scanf_s("%d", &size);
	printf("enter the array ele\n");
	for (i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("enter sum:");
	scanf_s("%d", &sum);
	for (i = 0; i < size; i++) {
		a = 0;
		for (j = i; j < size; j++) {
			a = a + arr[j];
			if (a == sum) {
				printf("%d\n", i);
				printf("%d\n", j);
				return 0;
			}
			if (a > sum) {
				break;
		}
		}
	}
	printf("No array found\n");
	return 0;
}