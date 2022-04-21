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

	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0), dp(k+1, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	dp[0] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=v[i];j<=k;j++)
		{
			dp[j] += dp[j-v[i]];
		}
	}
	cout << dp[k] << endl;

	return 0;
}
