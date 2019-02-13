#include<stdio.h>
#include<string.h>
int main() {
	char text[80];
	int i, a,b,ch=0,num=0,sp=0,spc=0,tb=0;
	printf("Enter the paragraph\n");
	gets(text);
	for (i = 0; i < strlen(text); i++) {
		a = text[i];
		if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122))) {
			ch++;
			spc = 0;
		}
		if (a >= 48 && a <= 57) {
			num++;
			spc = 0;
		}
		if (a == 32) {
			sp++;
			spc++;
			if (spc == 4) {
				tb++;
				spc = 0;
			}
		}

	
	}

	printf("space: %d  char: %d  digit: %d  tab: %d  ", sp, ch, num, tb);
	return 0;
}