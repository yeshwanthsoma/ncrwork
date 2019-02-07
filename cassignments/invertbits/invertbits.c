#include<stdio.h>
void invertponwards(int n, int p, int b) {
	int ar[8], i, a;
	for (i = 0; i < 8; i++) {
		ar[i] = 0;
	}
	i = 7;
	while (n > 0){
		a = n % 2;
		ar[i] = a;
		n = n / 2;
		i--;
	}
	for (i = p; i <= p + b; i++) {
		if (ar[i] == 1) {
			ar[i] = 0;
		}
		else {
			ar[i] = 1;
			
		}
	}
	printf("\n");
	for (i = 0; i < 8; i++) {
	printf("%d", ar[i]);
	}
}
int main() {
	int num,p,b;
	printf("Enter a number :\n");
	scanf_s("%d", &num);
	printf("\nEnter p and b ");
	scanf_s("%d%d", &p, &b);
	invertponwards(num, p, b);
	return 0;
}
