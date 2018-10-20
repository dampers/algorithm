# include <stdio.h>

int main()
{
	int a, b, c, k;
	scanf("%d %d %d", &a, &b, &c);
	if(c-b>0) k = 1 + a/(c-b);
	else k = -1;
	printf("%d", k);
	return 0;
}
