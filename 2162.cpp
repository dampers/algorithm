#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class DisjointSet
{
public:
	vector<int> parent, rank;
	DisjointSet(){}
	DisjointSet(int size)
	{
		parent.resize(size+1, 0);
		rank.resize(size+1, 1);
		for(size_t i=0;i<parent.size();i++)
			parent[i] = i;
	}
	int find(int v)
	{
		if(parent[v] == v) return v;
		return parent[v] = find(parent[v]);
	}
	bool merge(int u, int v)
	{
		u = find(u);
		v = find(v);
		if(u == v) return false;
		if(rank[v] >= rank[u])
		{
			parent[u] = v;
			rank[v] += rank[u];
		}
		else
		{
			parent[v] = u;
			rank[u] += rank[v];
		}
		return true;
	}
};

int ccw(pii a, pii b, pii c)
{
	int ans = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);
	if(ans > 0) return 1;
	else if(ans < 0) return -1;
	return 0;	
}

bool check(pii a, pii b, pii c, pii d)
{
	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);
	if(abc * abd == 0 && cda * cdb == 0)
	{
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	DisjointSet DS(n);
	vector<pair<pii, pii>> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(check(v[i].first, v[i].second, v[j].first, v[j].second))
			{
				DS.merge(i, j);
			}
		}
	}
	int num = 0, mx = 0;
	for(int i=0;i<n;i++)
	{
		if(DS.find(i) == i)
		{
			num++;
			mx = max(mx, DS.rank[i]);
		}
	}

	cout << num << endl << mx;

	return 0;
}