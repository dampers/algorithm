#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int parent[1000001];
int level[1000001];


int find(int n)
{
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(level[u]>level[v]) swap(u, v);
	parent[u] = v;
	if(level[u]==level[v]) level[v]++;
}



int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		parent[i] = i;
	for(int i=0;i<m;i++)
	{
		int t, a, b;
		cin>>t>>a>>b;
		if(t==0)
		{
			merge(a, b);
		}
		else
		{
			a = find(a);
			b = find(b);
			if(a==b) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
	return 0;
}