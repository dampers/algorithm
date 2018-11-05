# include <stdio.h>
# include <string.h>

char alp[22];

int main()
{
	int t, i, j, r, k;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d %s", &r, alp);
		for(j=0;j<strlen(alp);j++)
		{
			for(k=0;k<r;k++)
			{
				printf("%c", alp[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
