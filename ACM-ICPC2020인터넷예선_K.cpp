#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

class Compare
{
public:
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
	{return a.first>b.first;}
};

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin>>n>>m;
	vector<vector<int>> cost(n, vector<int>(m));
	vector<vector<int>> mp(n, vector<int>(m, INT_MAX));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>cost[i][j];
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
	if(cost[0][0]==-1)
	{
		cout<<-1;
		return 0;
	}
	mp[0][0] = cost[0][0];
	pq.push({mp[0][0], {0, 0}});
	while(!pq.empty())
	{
		int ncost = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		for(int i=0;i<4;i++)
		{
			int ny = y+dy[i], nx = x+dx[i];
			if(ny>=n || nx>=m || ny<0 || nx<0) continue;
			if(cost[ny][nx]==-1) continue;
			if(ncost+cost[ny][nx]<mp[ny][nx])
			{
				mp[ny][nx] = ncost+cost[ny][nx];
				pq.push({mp[ny][nx], {ny, nx}});
			}
		}
	}
	if(mp[n-1][m-1]==INT_MAX) cout<<-1;
	else cout<<mp[n-1][m-1];
	return 0;
}