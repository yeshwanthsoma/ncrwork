#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c,i,flag=0,x,y,j;
	printf("enter range");
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	for (i = x; i <=y; i++) {
		b = pow(i, 0.5);
		flag = 0;
		for (j = 2; j <= b; j++) {
			if (i%j == 0) {
				flag =1;
				break;
			}
		}
			if (flag == 0)
				printf("%d\n", i);
		
	
	}
	return 0;
}