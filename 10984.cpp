# include <stdio.h>

int main()
{
	int t, n;
	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		scanf(" %d", &n);
		int cnt = 0, tmp;
		double gcnt = 0, ttmp;
		for(int j=0;j<n;j++)
		{
			scanf(" %d %lf", &tmp, &ttmp);
			cnt += tmp;
			gcnt += tmp*ttmp;
			printf("%f\n", gcnt);
		}
		printf("%d %.1f", cnt, gcnt/cnt);
	}
	return 0;
}
