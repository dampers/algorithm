#include<stdio.h>

int main()
{
	int n,i,tmp=0,sum=0;
	char spell;
	
	scanf("%d\n", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%c", &spell);
		tmp=spell-64;
		sum+=tmp;
	}
	
	printf("%d", sum);

	return 0;
}
