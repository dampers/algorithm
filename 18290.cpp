#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k;
int ans = INT_MIN;
void recurr(int sum, int pos, int r, int c, vector<vector<int>>& v, vector<vector<bool>>& check)
{
	int ret = sum;
	if(pos == k)
	{
		ans = max(ans, ret);
		return;
	}
	for(int i=r;i<n;i++)
	{
		for(int j=c;j<m;j++)
		{
			if(check[i][j]) continue;
			bool flag = false;
			for(int d=0;d<4;d++)
			{
				int ny = i+dy[d], nx = j+dx[d];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if(check[ny][nx])
				{
					flag = true;
					break;
				}
			}
			if(flag) continue;
			check[i][j] = true;
			recurr(sum+v[i][j], pos+1, i, j, v, check);
			check[i][j] = false;
		}
		c = 0;
	}
}


int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	vector<vector<int>> v(n, vector<int>(m, 0));
	vector<vector<bool>> check(n, vector<bool>(m, false));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> v[i][j];
		}
	}
	recurr(0, 0, 0, 0, v, check);
	cout << ans;
	return 0;
}
