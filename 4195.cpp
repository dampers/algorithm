#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[200005], cnt[200005];

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
	if(cnt[u]>cnt[v])
	{
		parent[v] = u;
		cnt[u] += cnt[v];
	}
	else
	{
		parent[u] = v;
		cnt[v] += cnt[u];
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int f;
		cin>>f;
		int mcnt = 1;
		map<string, int> mp;
		string a, b;
		for(int i=0;i<f;i++)
		{
			cin>>a>>b;
			if(mp[a]==0)
			{
				parent[mcnt] = mcnt;
				cnt[mcnt] = 1;
				mp[a] = mcnt++;
			}
			if(mp[b]==0)
			{
				parent[mcnt] = mcnt;
				cnt[mcnt] = 1;
				mp[b] = mcnt++;
			}
			merge(mp[a], mp[b]);
			cout<<cnt[find(mp[a])]<<endl;
		}
	}
	return 0;
}