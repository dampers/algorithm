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

	int n, g, k;
	cin >> n >> g >> k;
	vector<pair<int, pii>> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first >> v[i].second.first >> v[i].second.second;
	}

	int left = 0, right = INT_MAX, ans = 0;
	vector<pii> tmp(n);
	while(left < right)
	{
		int mid = (left+right)/2;
		for(int i=0;i<n;i++)
		{
			tmp[i].first = v[i].second.second;
			tmp[i].second = v[i].first * max(1ll, mid-v[i].second.first);
		}
		sort(tmp.begin(), tmp.end());
		int tmpg = 0, tmpk = k;
		for(int i=0;i<n;i++)
			tmpg += tmp[i].second;
		for(int i=n-1;i>=0 && tmpk > 0;i--)
		{
			if(tmp[i].first == 0) break;
			tmpk--;
			tmpg -= tmp[i].second;
		}
		if(tmpg <= g)
		{
			ans = max(ans, mid);
			left = mid+1;
		}
		else right = mid;
	}
	cout << ans;


	return 0;
}
