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
	vector<string> v(n, "");
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
	}
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int cnt = 0;
			for(size_t ii=0;ii<v[i].length();ii++)
			{
				if(v[i][ii] == v[j][ii]) cnt++;
				else break;
			}
			mx = max(mx, cnt);
		}
	}
	cout << mx+1;
	return 0;
}
