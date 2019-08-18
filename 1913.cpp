#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int a[1051][1051];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	a[500][500] = 1;
	a[499][500] = 2;
	a[499][501] = 3;
	a[500][501] = 4;
	int t = 4;
	int x = 501, y = 500;
	for(int i=3;i<=n;i++)
	{
		if(i%2)
		{
			a[++y][x] = ++t;
			for(int j=1;j<i;j++)
				a[y][--x] = ++t;
			for(int j=1;j<i;j++)
				a[--y][x] = ++t;
		}
		else
		{
			a[--y][x] = ++t;
			for(int j=1;j<i;j++)
				a[y][++x] = ++t;
			for(int j=1;j<i;j++)
				a[++y][x] = ++t;
		}
	}
	bool xflag = false;
	x = 0;
	y = 0;
	for(int i=0;i<1005;i++)
	{
		if(!xflag) x = 0;
		bool flag = false;
		for(int j=0;j<1005;j++)
		{
			if(a[i][j])
			{
				printf("%d ", a[i][j]);
				flag = true;
				if(!xflag) x++;
			}
			if(a[i][j]==k) xflag = true;
		}
		if(!xflag && flag) y++;
		if(flag) printf("\n");
	}
	printf("%d %d", y+1 , x);
	return 0;
}