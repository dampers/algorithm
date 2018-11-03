# include <stdio.h>

int main()
{
	long long t, i, n, m, j;
	double c;
	scanf("%lld", &t);
	for(i=0;i<t;i++)  //mCn ±¸ÇÏÀÚ. 
	{
		c = 1;
		scanf("%lld %lld", &n, &m);
		for(j=1;j<=n;j++)
		{
			c *= m;
			c /= j;
			m--;
		}
		printf("%.0lf\n", c);
	}
	return 0;
}
