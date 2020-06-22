#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[10001];
int kcost;
void prim(int v)
{
	visit[v] = true;
	for(int i=0;i<edge[v].size();i++)
	{
		if(!visit[edge[v][i].second]) pq.push({edge[v][i].first, edge[v][i].second});
	}
	while(!pq.empty())
	{
		auto w = pq.top();
		pq.pop();
		if(!visit[w.second])
		{
			kcost += w.first;
			v = w.second;
			visit[v] = true;
			for(int i=0;i<edge[v].size();i++)
				if(!visit[edge[v][i].second]) pq.push({edge[v][i].first, edge[v][i].second});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin>>v>>e;
	edge.resize(v+1);
	int x, y, cost;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>cost;
		edge[x].push_back({cost, y});
		edge[y].push_back({cost, x});
	}
	prim(1);
	cout<<kcost;
	return 0;
}