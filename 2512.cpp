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

	int n, left = 0, right = 0;
	cin >> n;
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		right = max(right, v[i]);
	}
	right++;
	int m;
	cin >> m;
	int ans = 0;
	while(left < right)
	{
		int mid = (left+right)/2;
		int tmp = 0;
		for(int &K : v)
		{
			if(mid > K) tmp += K;
			else tmp += mid;
		}
		if(tmp <= m)
		{
			ans = max(ans, mid);
			left = mid+1;
		}
		else right = mid;
	}
	cout << ans << endl;

	return 0;
}
