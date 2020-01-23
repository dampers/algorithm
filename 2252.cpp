#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int check[32001];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<vector<int>> adj(32001);
	for(int i=0;i<m;i++)
	{
		int tmp1, tmp2;
		cin>>tmp1>>tmp2;
		adj[tmp1].push_back(tmp2);
		check[tmp2]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(check[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int tmp = q.front();
			cout<<tmp<<' ';
			q.pop();
			int adjsize = adj[tmp].size();
			for(int j=0;j<adjsize;j++)
			{
				if(--check[adj[tmp][j]]==0) q.push(adj[tmp][j]);
			}
		}
	}
	return 0;
}