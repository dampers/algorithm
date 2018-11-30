#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str
{
	char a[101];
	char b[101];
	char c[101];
};
int main()
{
	struct str t;
	gets(t.a);
	gets(t.b);
	gets(t.c);
	int n, j;
	scanf(" %d", &n);
	if(n == 1)
	{
		int len = strlen(t.a);
		for(j=len-1;j>=0;j--)
		{
			printf("%c", t.a[j]);
		}
	}
	if(n == 2)
	{
		int len = strlen(t.b);
		for(j=len-1;j>=0;j--)
		{
			printf("%c", t.b[j]);
		}
	}
	if(n == 3)
	{
		int len = strlen(t.c);
		for(j=len-1;j>=0;j--)
		{
			printf("%c", t.c[j]);
		}
	}
	return 0;
}