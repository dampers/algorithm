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
				tmp.x = coordi[i].x;
				tmp.y = coordi[i].y;
				coordi[i].x = coordi[j].x;
				coordi[i].y = coordi[j].y;
				coordi[j].x = tmp.x;
				coordi[j].y = tmp.y;
			}
			else if(coordi[i].x == coordi[j].x)
			{
				if(coordi[i].y>coordi[j].y)
				{
					tmp.x = coordi[i].x;
					tmp.y = coordi[i].y;
					coordi[i].x = coordi[j].x;
					coordi[i].y = coordi[j].y;
					coordi[j].x = tmp.x;
					coordi[j].y = tmp.y;
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
