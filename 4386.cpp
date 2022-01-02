#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

double getDistance(pair<double, double> a, pair<double, double> b)
{
	return pow((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second), 0.5);
}

#define SIZE 101
class Disjoint_Set
{
public:
	int parent[SIZE+1];
	Disjoint_Set()
	{
		for(int i=1;i<=SIZE;i++)
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
		parent[u] = v;
		return true;
	}
};

Disjoint_Set DS;

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<double, double>> points(n+1);
	for(int i=1;i<=n;i++)
	{
		cin >> points[i].first >> points[i].second;
	}
	vector<pair<double, pii>> dists;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dists.push_back({getDistance(points[i], points[j]), {i, j}});
		}
	}
	sort(dists.begin(), dists.end());
	double ans = 0.0;
	for(size_t i=0;i<dists.size();i++)
	{
		if(DS.merge(dists[i].second.first, dists[i].second.second))
		{
			ans += dists[i].first;
		}
	}
	cout << ans;

	return 0;
}