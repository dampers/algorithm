#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[101], k[101];
char g[205];
int c[205];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	scanf("%d %d", &n, &m);
	scanf(" %s %s", s, k);
	int mn = min(n, m);
	int ind = 0;
	for(int i=0;i<2*mn;i++)
	{
		if(i%2)
		{
			g[i] = k[ind];
			ind++;
		}
		else
			g[i] = s[ind];
	}
	if(n>m)
	{
		for(int i=2*mn;i<n+m;i++)
		{
			g[i] = s[ind];
			ind++;
		}
	}
	else if(n<m)
	{
		for(int i=2*mn;i<m+n;i++)
		{
			g[i] = k[ind];
			ind++;
		}
	}
	for(int i=0;i<n+m;i++)
	{
		if(g[i]=='A')
			c[i] = 3;
		else if(g[i]=='B')
			c[i] = 2;
		else if(g[i]=='C')
			c[i] = 1;
		else if(g[i]=='D')
			c[i] = 2;
		else if(g[i]=='E')
			c[i] = 4;
		else if(g[i]=='F')
			c[i] = 3;
		else if(g[i]=='G')
			c[i] = 1;
		else if(g[i]=='H')
			c[i] = 3;
		else if(g[i]=='I')
			c[i] = 1;
		else if(g[i]=='J')
			c[i] = 1;
		else if(g[i]=='K')
			c[i] = 3;
		else if(g[i]=='L')
			c[i] = 1;
		else if(g[i]=='M')
			c[i] = 3;
		else if(g[i]=='N')
			c[i] = 2;
		else if(g[i]=='O')
			c[i] = 1;
		else if(g[i]=='P')
			c[i] = 2;
		else if(g[i]=='Q')
			c[i] = 2;
		else if(g[i]=='R')
			c[i] = 2;
		else if(g[i]=='S')
			c[i] = 1;
		else if(g[i]=='T')
			c[i] = 2;
		else if(g[i]=='U')
			c[i] = 1;
		else if(g[i]=='V')
			c[i] = 1;
		else if(g[i]=='W')
			c[i] = 1;
		else if(g[i]=='X')
			c[i] = 2;
		else if(g[i]=='Y')
			c[i] = 2;
		else if(g[i]=='Z')
			c[i] = 1;
	}
	//printf("%s\n", g);
	//printf("%d\n", strlen(g));
	for(int i=0;i<n+m-2;i++)
	{
		for(int j=0;j<n+m-1-i;j++)
		{
			c[j] = (c[j+1]+c[j])%10;
		}
	}
	if(c[0]==0)
		printf("%d%%", c[1]);
	else
		printf("%d%d%%", c[0], c[1]);
	return 0;
}