# include <stdio.h>

typedef struct coordi
{
	int x, y;
}crd;

crd coordi[100001];

int main()
{
	int n, i, j;
	crd tmp;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d", &coordi[i].x, &coordi[i].y);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(coordi[i].x>coordi[j].x)
			{
				tmp = coordi[i];
				coordi[i] = coordi[j];
				coordi[j] = tmp;
			}
			else if(coordi[i].x == coordi[j].x)
			{
				if(coordi[i].y>coordi[j].y)
				{
					tmp = coordi[i];
					coordi[i] = coordi[j];
					coordi[j] = tmp;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n", coordi[i].x, coordi[i].y);
	}
	return 0;
}
