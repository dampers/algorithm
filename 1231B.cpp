#include<bits/stdc++.h>

using namespace std;

int p[1001][3];
int v[1001][3];
int c[1001];
int cp[1001];
int n;
int f(int x,int y,int cpp)
{
	int xx, yy;
	printf("\n%d START!\n\n", cpp);
	if(cpp == n-1)
	{
		printf("END\n");
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		printf("i = %d\n", i);
		for(int j=0;j<n;j++)
		{
			printf("j = %d\n", j);
			printf("cp[%d] = %d c[%d] = %d n = %d\n", i, cp[i], j, c[j], n);
			if(cp[i] == 0 && c[j] == 0)
			{
				xx = p[i][0] + v[j][0];
				yy = p[i][1] + v[j][1];
				cp[i] = 1;
				c[j] = 1;
				printf("xx = %d + %d	yy = %d + %d\n", p[i][0], v[j][0], p[i][1], v[j][1]);
				printf("xx = %d yy = %d\n", xx, yy);
				if(xx==x && y==yy)
				{
					printf("%d %d", xx, yy);
					f(x, y, ++cpp);
					return 1;
				}
				else if(xx != x|| yy != y)
				{
					for(int k=0;k<n;k++)
					{
						c[k] = 0;
						cp[k] = 0;
					}
					printf("\n\nwrong!\n\n\n");
					return 0;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d", &p[i][0], &p[i][1]);
	}
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d", &v[i][0], &v[i][1]);
	}
	int x, y, flag = 0;
	for(int i=0;i<n;i++)
	{
		printf("i = %d\n", i);
		for(int j=0;j<n;j++)
		{
			printf("j = %d\n", j);
			if(cp[i] == 0 && c[j] == 0)
			{
				printf("cp[%d] = %d c[%d] = %d n = %d\n", i, cp[i], j, c[j], n);
				x = p[i][0] + v[j][0];
				y = p[i][1] + v[j][1];
				c[j] = 1;
				cp[i] = 1;
				printf("x = %d + %d	y = %d + %d\n", p[i][0], v[j][0], p[i][1], v[j][1]);
				printf("x = %d y = %d\n", x, y);
			}
			flag = f(x,y,0);
			if(flag==1)
			{
				break;
			}
		}
		if(flag==1)
		{
			printf("%d %d", x, y);
			break;
		}
		for(int k=0;k<n;k++)
		{
			c[k] = 0;
			cp[k] = 0;
		}
	}
	return 0;
}
