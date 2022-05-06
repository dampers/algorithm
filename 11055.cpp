#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int recurr(int pos, int pre, vector<int>& v, vector<int>& dp)
{
	int &ret = dp[pos];
	if(ret > 0) return ret;
	for(size_t i=pos;i<v.size();i++)
	{
		if(v[i] > pre) ret = max(ret, v[i]+recurr(i, v[i], v, dp));
	}
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	vector<int> dp(n, 0);
	cout << recurr(0, 0, v, dp);

	return 0;
}
