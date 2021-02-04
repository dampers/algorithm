#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void find_parent(int node, vector<vector<int>>& tree, vector<int>& check)
{
	for(size_t i=0;i<tree[node].size();i++)
	{
		int child = tree[node][i];
		if(!check[child])
		{
			check[child] = node;
			find_parent(child, tree, check);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<vector<int>> tree(n+1, vector<int>());
	vector<int> check(n+1, 0);
	for(int i=0;i<n-1;i++)
	{
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	check[1] = 1;
	find_parent(1, tree, check);
	for(int i=2;i<=n;i++)
		cout << check[i] << endl;
	return 0;
}