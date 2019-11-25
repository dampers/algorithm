#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int wook[303][303];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>wook[i][j];
	int mx = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			wook[i][j] = max(wook[i-1][j], wook[i][j-1])+wook[i][j];
			mx = max(mx, wook[i][j]);
		}
	}
	cout<<mx;
	return 0;
}