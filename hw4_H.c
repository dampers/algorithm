# include <stdio.h>
# include <string.h>

char alp[101];

int main()
{
	int n, m, i, j, k = 0, cnt, a;
	scanf("%d %d", &n, &m);
	scanf(" %s", alp);
	cnt = n/m;
	for(i=0;i<m;i++)
	{
		k += cnt;
		for(a=k-1;a>=k-cnt;a--)
		{
			printf("%c", alp[a]);
		}
	}
	printf("\n\n");
	return 0;
}
