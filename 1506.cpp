#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<int> DFSn, SCCn;
vector<bool> finished;
int DFS_NUM, SCC_NUM;
stack<int> S;
int n;

int dfs(int node, vector<string>& adj)
{
	if(DFSn[node]) return DFSn[node];
	DFSn[node] = ++DFS_NUM;
	int ret = DFSn[node];
	S.push(node);
	for(int i=0;i<n;i++)
	{
		if(adj[node][i] == '1')
		{
			if(finished[i]) continue;
			ret = min(ret, dfs(i, adj));
		}
	}
	if(ret == DFSn[node])
	{
		while(1)
		{
			int curr = S.top();
			S.pop();
			SCCn[curr] = SCC_NUM;
			finished[curr] = true;
			if(curr == node) break;
		}
		SCC_NUM++;
	}
	return ret;
}

 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> cost(n, 0);
	for(int i=0;i<n;i++)
		cin >> cost[i];
	vector<string> adj(n, "");
	for(int i=0;i<n;i++)
		cin >> adj[i];
	DFSn.resize(n, 0);
	SCCn.resize(n, 0);
	finished.resize(n, false);

	for(int i=0;i<n;i++)
	{
		if(finished[i]) continue;
		dfs(i, adj);
	}
	vector<int> SCC_COST(SCC_NUM, INT_MAX);
	for(int i=0;i<n;i++)
	{
		int scc_number = SCCn[i];
		SCC_COST[scc_number] = min(SCC_COST[scc_number], cost[i]);
	}
	int ans = 0;
	for(int i=0;i<SCC_NUM;i++)
		ans += SCC_COST[i];
	
	cout << ans;

	return 0;
}