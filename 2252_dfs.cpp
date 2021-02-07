#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void dfs(int edge, vector<vector<int>>& v, vector<bool>& check)
{
	if(check[edge]) return;
	check[edge] = true;
	for(size_t i=0;i<v[edge].size();i++)
	{
		if(!check[v[edge][i]])
		{
			dfs(v[edge][i], v, check);
		}
	}
	cout << edge <<' ';
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1, vector<int>());
	vector<bool> check(n+1, false);
	for(int i=0, a, b;i<m;i++)
	{
		cin >> a >> b;
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i, v, check);
	}

	return 0;
}