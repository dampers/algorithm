#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

vector<int> inorder, postorder;
vector<vector<int>> tree;
map<int, int> inorder_index;

int make_tree(int left, int right, int pos)
{
	if(pos == -1) return pos;
	int idx = inorder_index[postorder[pos]];
	if(left <= idx && idx <= right)
	{
		int lpos = make_tree(idx+1, right, pos-1);
		if(lpos < pos-1) tree[postorder[pos]].push_back(postorder[pos-1]);
		int retpos = make_tree(left, idx-1, lpos);
		if(retpos < lpos) tree[postorder[pos]].push_back(postorder[lpos]);
		return retpos;
	}
	return pos;
}

void preorder(int node)
{
	cout << node << ' ';
	for(auto rit = tree[node].rbegin(); rit != tree[node].rend(); ++rit)
		preorder(*rit);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	inorder = vector<int>(n, 0);
	postorder = vector<int>(n, 0);
	tree = vector<vector<int>>(n+1, vector<int>());
	for(int i=0;i<n;i++)
	{
		cin >> inorder[i];
		inorder_index[inorder[i]] = i;
	}
	for(int i=0;i<n;i++)
		cin >> postorder[i];

	make_tree(0, n-1, n-1);
	preorder(postorder[n-1]);

	return 0;
}