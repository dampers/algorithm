#include <stdio.h>
#include <string.h>

char alp[101];

int main()
{
	gets(alp);
	printf("%d", strlen(alp));
	return 0;
}