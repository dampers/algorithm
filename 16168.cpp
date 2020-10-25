#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

bool dfs(int v, int e, int pos, vector<queue<int>>& tree, vector<vector<int>>& check)
{
	if(pos==e) return true;
	while(!tree[v].empty())
	{
		int next = tree[v].front();
		tree[v].pop();
		if(check[v][next]) continue;
		check[v][next] = 1;
		check[next][v] = 1;
		return dfs(next, e, pos+1, tree,check);
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin>>v>>e;
	vector<queue<int>> tree(v+1);
	int start = 1;
	for(int i=0;i<e;i++)
	{
		int a, b;
		cin>>a>>b;
		tree[a].push(b);
		tree[b].push(a);
		if(tree[a].size()>2) start = a;
	}
	vector<vector<int>> check(v+1, vector<int> (v+1, 0));
	if(dfs(start, e, 0, tree, check)) cout<<"YES";
	else cout<<"NO";
	return 0;
}