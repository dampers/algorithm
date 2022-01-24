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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n+1, vector<int>());
		for(int i=0;i<m;i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans = 0;
		queue<int> q;
		q.push(1);
		vector<bool> check(n+1, false);
		check[1] = true;
		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			for(auto& K : v[curr])
			{
				if(check[K]) continue;
				check[K] = true;
				q.push(K);
				ans++;
			}
		}
		cout << ans << endl;

	}

	return 0;
}