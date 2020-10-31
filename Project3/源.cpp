#include <stdio.h>  
void output1(int x1,char ch)
{
	int i;
	for (i = 1;i <= x1;i++)
	printf("%c", ch);
}

int main(void)
{
	int a, n;
	scanf_s("%d", &a);
	n = 1;
	char m;
	m = '*';
	for (n = 1;n <= 2*a;n = n + 2) {
		output1(n, m);
		printf("\n");
	}
}

   


