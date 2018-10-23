# include <stdio.h>

char mir[101][101];

int main()
{
	int n, i, j, s;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%s", mir[i]);
	scanf("%d", &s);
	if(s==1)
		for(i=0;i<n;i++)
			printf("%s\n", mir[i]);
	
	else if(s==2)
	{
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--) printf("%c", mir[i][j]);
			printf("\n");
		}
	}
	
	else if(s==3)
	{
		for(i=n-1;i>=0;i--) printf("%s\n", mir[i]);
	}
	return 0;
}
