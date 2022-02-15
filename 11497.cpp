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

	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for(int i=0;i<n;i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int left = v[0], right = v[0];
		int ans = abs(v[0]-v[1]);
		for(int i=1;i<n;i++)
		{
			if(i%2)
			{
				ans = max(ans, abs(left-v[i]));
				left = v[i];
			}
			else
			{
				ans = max(ans, abs(right-v[i]));
				right = v[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
