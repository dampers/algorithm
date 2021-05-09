#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> city(n+1, vector<int>(n+1, (int)1e9));
	for(int i=1;i<=n;i++)
		city[i][i] = 0;

	int s, e, c;
	for(int i=0;i<m;i++)
	{
		cin >> s >> e >> c;
		city[s][e] = min(city[s][e], c);
	}

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(city[i][j] > city[i][k]+city[k][j])
					city[i][j] = city[i][k]+city[k][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(city[i][j] >= (int)1e9) cout << 0 << ' ';
			else cout << city[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}