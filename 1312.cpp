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

	int a, b, n;
	cin >> a >> b >> n;
	int cnt = 0, k = a%b, ans = 0;
	if(a%b == 0)
	{
		cout << 0;
		return 0;
	}
	while(cnt < n)
	{
		cnt++;
		k *= 10;
		if(k < b)
		{
			ans = 0;
		}
		else
		{
			ans = k/b;
			k %= b;
		}
	}

	cout << ans;

	return 0;
}