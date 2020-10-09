#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

class Compare
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second>b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int vs, e;
	cin>>vs>>e;
	vector<vector<pair<int, int>>> v(vs+1);
	vector<int> cost(vs+1, INT_MAX);
	int k;
	cin>>k;
	cost[k] = 0;
	for(int i=0;i<e;i++)
	{
		int a, b, w;
		cin>>a>>b>>w;
		v[a].push_back({b, w});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({k, 0});
	while(!pq.empty())
	{
		int u = pq.top().first, tcost = pq.top().second;
		pq.pop();
		cost[u] = min(cost[u], tcost);
		for(int i=0;i<v[u].size();i++)
		{
			if(cost[v[u][i].first]>tcost+v[u][i].second)
			{
				cost[v[u][i].first] = tcost+v[u][i].second;
				pq.push({v[u][i].first, tcost+v[u][i].second});
			}
		}
	}
	for(int i=1;i<=vs;i++)
	{
		if(cost[i]==INT_MAX) cout<<"INF"<<endl;
		else cout<<cost[i]<<endl;
	}
	return 0;
}