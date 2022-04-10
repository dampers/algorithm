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

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	vector<bool> check(f+1, false);
	check[s] = true;

	bool flag = false;
	queue<int> q;
	q.push(s);
	int cnt = 0;
	if(s == g)
	{
		cout << 0;
		return 0;
	}
	while(!q.empty())
	{
		int size = q.size();
		cnt++;
		while(size--)
		{
			int curr = q.front();
			q.pop();
			if(curr + u <= f && !check[curr+u])
			{
				check[curr+u] = true;
				if(curr+u == g)
				{
					flag = true;
					break;
				}
				q.push(curr+u);
			}
			if(curr - d >= 1 && !check[curr-d])
			{
				check[curr-d] = true;
				if(curr-d == g)
				{
					flag = true;
					break;
				}
				q.push(curr-d);
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) cout << cnt;
	else cout << "use the stairs";
	return 0;
}
