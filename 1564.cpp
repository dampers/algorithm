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
	int ans = 1;
	for(int i=2;i<=n;i++)
	{
		int k = i;
		while(k%5 == 0)
		{
			k /= 5;
			ans >>= 1;
		}
		ans *= k;
		ans %= 1000000000000;
	}
	ans %= 100000;
	for(int i=10000;i>0;i/=10)
	{
		if(ans/i == 0) cout << 0;
	}
	cout << ans;
	return 0;
}
