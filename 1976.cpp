#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[202], level[202], linked[1001];

int find(int u)
{
	if(u==parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(parent[u]==parent[v]) return;
	if(level[u]>level[v]) swap(u, v);
	parent[u] = v;
	if(level[u]==level[v]) level[v]++;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, tmp;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		parent[i] = i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>tmp;
			if(tmp) merge(i, j);
		}
	}
	cin>>tmp;
	int root = find(tmp);
	bool flag = true;
	for(int i=1;i<m;i++)
	{
		cin>>tmp;
		tmp = find(tmp);
		if(root!=tmp) flag = false;
	}
	if(flag) cout<<"YES";
	else cout<<"NO";
	
	return 0;
}