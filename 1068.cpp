#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int del_node, leaf_cnt;

void count_leaf(int node, vector<vector<int>>& tree, vector<bool>& check)
{
	check[node] = true;
	if(tree[node].size() == 0)
	{
		leaf_cnt++;
		return;
	}
	if(tree[node].size() == 1 && tree[node][0] == del_node)
	{
		leaf_cnt++;
		return;
	}

	for(size_t i=0;i<tree[node].size();i++)
	{
		int tmp = tree[node][i];
		if(tmp == del_node) continue;
		if(check[tmp]) continue;
		count_leaf(tmp, tree, check);
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;

	vector<int> v(n, 0);
	vector<vector<int>> tree(n, vector<int>());
	vector<bool> check(n, false);
	int root = 0;
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		if(v[i] == -1)
		{
			root = i;
			continue;
		}
		tree[v[i]].push_back(i);
	}
	cin >> del_node;
	if(del_node == root)
	{
		cout << 0;
		return 0;
	}
	count_leaf(root, tree, check);
	cout<<leaf_cnt<<endl;
	return 0;
}