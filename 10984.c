# include <stdio.h>

int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf(" %d", &n);
		int cnt = 0, tmp;
		float gcnt = 0, ttmp;
		for(j=0;j<n;j++)
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
