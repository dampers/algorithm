#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<set<int>> vs;
	map<int, int> yv;
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> v(k, {0 ,0});
	for(int i=0;i<k;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int y = v[0].first, x = v[0].second;
	yv[y] = 0;
	vs.push_back(set<int>());
	vs[0].insert(x);
	for(int i=1;i<k;i++)
	{
		if(y < v[i].first)
		{
			yv[v[i].first] = yv[y]+1;
			y = v[i].first;
			vs.push_back(set<int>());
		}
		vs[yv[y]].insert(v[i].second);
	}

	int ans = 0;
	
	while(k)
	{
		ans++;
		int sy = 0;
		int sx = 0;
		for(size_t i=0;i<vs.size();i++)
		{
			if(vs[i].size() > 0)
			{
				sy = i;
				sx = *(vs[i].begin());
				break;
			}
		}
		for(size_t i=sy;i<vs.size();i++)
		{
			set<int>::iterator it;
			it = vs[i].lower_bound(sx);
			while(it != vs[i].end())
			{
				k--;
				sx = *it;
				it = vs[i].erase(it);
			}
		}
	}
	cout << ans;
	return 0;
}