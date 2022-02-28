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

	int p = 0, mx = 0;
	for(int i=0;i<10;i++)
	{
		int o, in;
		cin >> o >> in;
		p += in - o;
		mx = max(p, mx);
	}
	cout << mx;

	return 0;
}
