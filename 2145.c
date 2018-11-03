# include <stdio.h>

int main()
{
	int n, d;
	while(1)
	{
		scanf("%d", &d);
		if(d==0) break;
		while(d>9)
		{
			n = 0;
			while(d>0)
			{
				n += d%10;
				d/=10;
			}
			d = n;
		}
		printf("%d\n", d);
	}
	return 0;
}
