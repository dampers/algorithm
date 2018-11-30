#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stri
{
	char str[4][101];
};

int main()
{
	struct stri a;
	int i, n;
	for(i=1;i<4;i++)
	{
		gets(a.str[i]);
	}
	scanf(" %d", &n);
	int len = strlen(a.str[n]);
	for(i=len-1;i>=0;i--)
	{
		printf("%c", a.str[n][i]);
	}
	return 0;
}