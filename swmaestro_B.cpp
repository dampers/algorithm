#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[300005], level[300005];
pair<lld, lld> value[300005];
int find(int u)
{
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(level[u]>level[v]) swap(u, v);
	parent[u] = v;
	if(level[u]==level[v]) ++level[v];
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		parent[i] = i;
		level[i] = 1;
		lld tmp1, tmp2;
		cin>>tmp1>>tmp2;
		value[i].first = tmp1;
		value[i].second = tmp2;
	}
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		merge(u, v);
	}
	vector<int> root;
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==i) root.push_back(i);
		//cout<<parent[i]<<' ';
	}
	//vector<vector<int>> v(root.size());
	lld mn = 0LL;
	for(int i=0;i<root.size();i++)
	{
		lld mx = LLONG_MAX, my = LLONG_MAX, Mx = 1LL, My = 1LL;
		for(int j=1;j<=n;j++)
		{
			if(parent[j]==root[i])
			{
				mx = min(mx, value[j].first);
				my = min(my, value[j].second);
				Mx = max(Mx, value[j].first);
				My = max(My, value[j].second);
			}
		}
		mn = max(mn, ((My-my)+(Mx-mx))*2);
	}
	cout<<mn;
	return 0;
}