#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int v[303], dp[303];

int recur(int n)
{
	if(n < 0) return 0;
	int& ret = dp[n];
	if(ret > 0) return ret;
	ret = max(recur(n-2)+v[n], recur(n-3)+v[n-1]+v[n]);
	return ret;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> v[i];
	cout << recur(n);
	return 0;
}