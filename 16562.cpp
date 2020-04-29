#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[10005];
lld pay[10005];

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
	if(pay[u]>pay[v]) parent[u] = v;
	else parent[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	lld k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		parent[i] = i;
		cin>>pay[i];
	}
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		merge(a, b);
	}
	lld sum = 0LL;
	for(int i=1;i<=n;i++)
	{
		if(find(0)!=find(i))
		{
			sum += pay[find(i)];
			merge(0, i);
		}
	}
	if(k<sum) cout<<"Oh no";
	else cout<<sum;
	
	return 0;
}