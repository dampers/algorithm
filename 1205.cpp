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

	int n, t, p;
	cin >> n >> t >> p;
	if(n == 0)
	{
		cout << 1;
		return 0;
	}
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}

	if(v.back() == t && n == p)
	{
		cout << -1;
		return 0;
	}
	int ans = n+1;
	for(int i=0;i<n;i++)
	{
		if(v[i] <= t)
		{
			ans = i+1;
			break;
		}
	}
	if(ans > p) cout << -1;
	else cout << ans;

	return 0;
}
