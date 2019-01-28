#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int r[50000][50000];
int main()
{
	int n, m, t;
	r[0][0] = 1;
	for(int j=1;j<=50000;j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(k==0) r[j][k] = 1;
				else if(k==j)
				{
					r[j][k] = 1;
					break;
				}
				else r[j][k] = (r[j-1][k-1]*r[j-1][k]+1)/r[j-2][k-1];
			}
		}
	scanf(" %d", &t);
	for(int i=0;i<t;i++)
	{
		scanf(" %d %d", &n, &m);
		printf("%d\n", r[n][m]);
	}
	return 0;
}
