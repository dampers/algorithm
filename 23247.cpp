#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int32_t main()	
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1, vector<int>(m+1, 0)), psum(n+1, vector<int>(m+1, 0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> v[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + v[i][j];

	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int ii=0;i+ii<=n;ii++)
				for(int jj=0;j+jj<=m;jj++)
				{
					int tmp = psum[i+ii][j+jj] - psum[i+ii][j-1] - psum[i-1][j+jj] + psum[i-1][j-1];
					if(tmp == 10) ans++;
					if(tmp >= 10) break;
				}
	cout << ans;

	return 0;
}