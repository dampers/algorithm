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

	int n;
	cin >> n;
	vector<pii> v(n+1);
	vector<int> tmpx, tmpy;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i].first >> v[i].second;
		tmpx.emplace_back(v[i].first);
		tmpy.emplace_back(v[i].second);
	}
	sort(tmpx.begin(), tmpx.end());
	sort(tmpy.begin(), tmpy.end());

	vector<vector<int>> psum(n+1, vector<int>(n+1, 0));
	for(int i=1;i<=n;i++)
	{
		v[i].first = lower_bound(tmpx.begin(), tmpx.end(), v[i].first) - tmpx.begin() + 1;
		v[i].second = lower_bound(tmpy.begin(), tmpy.end(), v[i].second) - tmpy.begin() + 1;
		psum[v[i].first][v[i].second]++;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
		}
	}
	sort(v.begin(), v.end());
	int ans = n+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			int left = v[j].first, right = v[i].first;
			int low = v[j].second, high = v[i].second;
			if(low > high) swap(low, high);
			int tmp = 1;
			if(left <= right && high <= n)
			{
				tmp *= psum[right][n] - psum[left-1][n] - psum[right][high-1] + psum[left-1][high-1];				
			}
			else tmp = 0;
			if(left <= right && 1 <= low)
			{
				tmp *= psum[right][low] - psum[left-1][low] - psum[right][0] + psum[left-1][0];
			}
			else tmp = 0;
			ans += tmp;
		}
	}
	cout << ans;

	return 0;
}
