using namespace std;
#include<iostream>
void swap_value(int a,int b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap_ref(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
int main() {
	int i, a,b;
	printf("enter the values of a,b\n");
	scanf_s("%d%d", &a, &b);
	printf("enter the method:\n");
	printf("1.swap_value\n");
	printf("2.swap_ref\n");
	scanf_s("%d", &i);
	switch (i) {
		case 1:swap_value(a,b);
			   break;
		case 2:swap_ref(a,b);
			   break;
	}
	printf("a=%d  b=%d\n", a, b);
}