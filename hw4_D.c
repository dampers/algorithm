# include <stdio.h>

int score[11][2];

int main()
{
	int t, n, i, j, k, max, check;
	char ox;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		max = 0;
		scanf(" %d", &n);
		for(j=0;j<n;j++)
		{
			scanf(" %d", &score[j][0]);
			for(k=0;k<4;k++)
			{
				scanf(" %c", &ox);
				if(ox == 'O') score[j][1]++;
			}
			if(max<score[j][0]+score[j][1])
			{
				max = score[j][0]+score[j][1];
				check = j;
			}
		}
		printf("%d\n\n", score[check][0]);
	}
	
	return 0;
}
