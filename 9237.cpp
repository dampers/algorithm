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
	vector<int> v(n, 0);
	for(int i=0;i<n;i++)
		cin >> v[i];
	sort(v.begin(), v.end(), [](int a, int b){return a > b;});
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans = max(i+v[i]+1, ans);
	}
	cout << ans+1;
	return 0;
}
