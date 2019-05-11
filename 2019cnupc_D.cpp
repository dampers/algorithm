#include <bits/stdc++.h>
using namespace std;

int taxi[1001][1001];

int main()
{
	int n, m;
	scanf( "%d %d", &n, &m);
	pair<int , int> a, b;
	int x, y, xx, yy;
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %d", &taxi[i][j]);
			if(!flag&&taxi[i][j]==1)
			{
				flag = 1;
				x = j;
				y = i;
			}
			else if(flag&&taxi[i][j]==1)
			{
				xx = j;
				yy = i;
			}
		}
	}
	printf("%d", abs(xx-x)+abs(yy-y));
	return 0;
}