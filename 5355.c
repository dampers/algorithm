# include<stdio.h>
# include<string.h>

char yun[101];

int main()
{
	int n, i, j;
	double m;
	char y;
	scanf(" %d\n", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %lf", &m);
		gets(yun);
		for(j=1;j<strlen(yun);j++)
		{
			if(yun[j] == '@') m *= 3;
			else if(yun[j] == '%') m += 5;
			else if(yun[j] == '#') m -= 7;
		}
		printf("%.2lf\n", m);
	}
	return 0;
}
