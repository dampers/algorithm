#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[32001];
vector<vector<int>> adj(32001);
void dfs(int node)
{
	int size = adj[node].size();
	if(size==0)
	{
		cout<<node<<' ';
		check[node] = true;
		return ;
	}
	for(int i=size-1;i>=0;i--)
	{
		if(check[adj[node][i]])
		{
			adj[node].pop_back();
			continue;
		}
		dfs(adj[node][i]);
		check[adj[node][i]] = true;
		cout<<adj[node][i]<<' ';
		adj[node].pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int tmp1, tmp2;
		cin>>tmp1>>tmp2;
		adj[tmp2].push_back(tmp1);
	}
	for(int i=1;i<=n;i++)
	{
		if(!check[i]) continue;
		dfs(i);
	}
	return 0;
}