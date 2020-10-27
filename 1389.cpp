#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int floyd[105][105];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			floyd[i][j] = (int)1e9;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		floyd[a][b] = floyd[b][a] = 1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(floyd[i][j]>floyd[i][k]+floyd[k][j])
					floyd[i][j] = floyd[i][k]+floyd[k][j];
			}
		}
	}
	int mnind = 1, mn = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		int tmp = 0;
		for(int j=1;j<=n;j++)
		{
			tmp += floyd[i][j];
		}
		if(mn>tmp)
		{
			mnind = i;
			mn = tmp;
		}
	}
	cout<<mnind;
	return 0;
}