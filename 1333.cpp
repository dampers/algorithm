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

	int n, l, d;
	cin >> n >> l >> d;
	vector<int> v(n*l+5*(n-1)+1, 0);
	for(int i=0;i<n;i++)
	{
		int s = (l+5)*i;
		for(int j=s;j<s+l;j++)
			v[j] = 1;
	}
	int ans = 0;
	while(ans < v.size())
	{
		if(!v[ans]) break;
		ans += d;
	}
	cout << ans;

	return 0;
}
