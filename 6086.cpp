#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	const int MAXV = 707;
	scanf("%d", &n);
	vector<vector<int>> adj(MAXV, vector<int>());
	vector<vector<int>> capacity(MAXV, vector<int>(MAXV, 0));
	vector<vector<int>> flows(MAXV, vector<int>(MAXV, 0));
	char u, v;
	int c;
	for(int i=0;i<n;i++)
	{
		scanf(" %c %c %d", &u, &v, &c);
		if('A' <= u && u <= 'Z') u -= 'A';
		else u = u -'a' + 26;
		if('A' <= v && v <= 'Z') v -= 'A';
		else v = v -'a' + 26;
		
		adj[u].push_back((int)v);
		adj[v].push_back((int)u);
		capacity[u][v] += c;
		capacity[v][u] += c;
	}

	int total = 0, start = 0, end = 25;
	while(1)
	{
		int prev[MAXV];
		fill(prev, prev+MAXV, -1);
		queue<int> q;
		q.push(start);
		while(!q.empty() && prev[end] == -1)
		{
			int cur = q.front();
			q.pop();
			for(size_t i=0;i<adj[cur].size();i++)
			{
				int next = adj[cur][i];
				if(capacity[cur][next]-flows[cur][next] > 0 && prev[next] == -1)
				{
					q.push(next);
					prev[next] = cur;
					if(next == end) break;
				}
			}
		}
		if(prev[end] == -1) break;
		int flow = INT_MAX;
		for(int i=end;i!=start;i=prev[i])
		{
			printf("%d ", i);
			flow = min(flow, capacity[prev[i]][i]-flows[prev[i]][i]);
		}
		printf("\n");
		for(int i=end;i!=start;i=prev[i])
		{
			flows[prev[i]][i] += flow;
			flows[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d", total);


	return 0;
}