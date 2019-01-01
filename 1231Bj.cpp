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
	if(cpp == n-1)
	{
		return 1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(cp[i] == 0 && c[j] == 0)
			{
				xx = p[i][0] + v[j][0];
				yy = p[i][1] + v[j][1];
				cp[i] = 1;
				c[j] = 1;
				if(xx==x && y==yy)
				{
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
		for(int j=0;j<n;j++)
		{
			if(cp[i] == 0 && c[j] == 0)
			{
				x = p[i][0] + v[j][0];
				y = p[i][1] + v[j][1];
				c[j] = 1;
				cp[i] = 1;
			}
			flag = f(x,y,0);
			if(flag==1)
			{
				break;
			}
			for(int k=0;k<n;k++)
			{
				c[k] = 0;
				cp[k] = 0;
			}
		}
		if(flag==1)
		{
			printf("%d %d", x, y);
			break;
		}
	}
	return 0;
}
