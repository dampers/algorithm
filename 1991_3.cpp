#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

void init_tree(int n, vector<vector<int>>& tree)
{
	for(int i=0;i<n;i++)
	{
		char parent, left, right;
		scanf(" %c %c %c", &parent, &left, &right);
		if(left != '.') tree[parent-'A'][0] = (left-'A');
		if(right != '.') tree[parent-'A'][1] = (right-'A');
	}
}

void preorder(int node, vector<vector<int>>& tree)
{
	printf("%c", node+'A');
	if(tree[node][0] != -1) preorder(tree[node][0], tree);
	if(tree[node][1] != -1) preorder(tree[node][1], tree);
}

void inorder(int node, vector<vector<int>>& tree)
{
	if(tree[node][0] != -1) inorder(tree[node][0], tree);
	printf("%c", node+'A');
	if(tree[node][1] != -1) inorder(tree[node][1], tree);
}

void postorder(int node, vector<vector<int>>& tree)
{
	if(tree[node][0] != -1) postorder(tree[node][0], tree);
	if(tree[node][1] != -1) postorder(tree[node][1], tree);
	printf("%c", node+'A');
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	scanf("%d", &n);
	vector<vector<int>> tree(n, vector<int>(2, -1));
	init_tree(n, tree);
	preorder(0, tree);
	printf("\n");
	inorder(0, tree);
	printf("\n");
	postorder(0, tree);

	return 0;
}