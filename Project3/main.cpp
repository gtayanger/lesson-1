#include <stdio.h>

void output1(int x1, char ch)
{
	for (int i = 1; i <= x1; i++)
		printf("%c", ch);
}

int main(void)
{
	int a;
	scanf_s("%d", &a);
	
	int n = 1;
	char m = '*';
	for (n = 1; n <= 2 * a; n = n + 2)
	{
		output1(n, m);
		printf("\n");
	}
}
