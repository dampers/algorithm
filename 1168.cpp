#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int get_next(int L, int R, int node, int order, vector<int>& seg_tree)
{
	if(L == R) return L;
	int mid = (L+R)/2;
	if(order <= seg_tree[node*2]) return get_next(L, mid, node*2, order, seg_tree);
	return get_next(mid+1, R, node*2+1, order-seg_tree[node*2], seg_tree);
}

void update(int nodeNum, int value, vector<int>& seg_tree)
{
	seg_tree[nodeNum] = 0;
	while(nodeNum > 1)
	{
		nodeNum /= 2;
		seg_tree[nodeNum] = seg_tree[nodeNum*2] + seg_tree[nodeNum*2+1];
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n, k;
	cin >> n >> k;
	int depth = (int)ceil(log2(n))+1;
	int tree_size = 1 << depth;
	int leaf_size = tree_size / 2;

	vector<int> seg_tree(tree_size, 0);
	for(int i=0;i<n;i++)
		seg_tree[i+leaf_size] = 1;
	for(int i=leaf_size-1;i>0;i--)
		seg_tree[i] = seg_tree[i*2] + seg_tree[i*2+1];

	int index = 1;
	cout << '<';
	for(int i=0;i<n;i++)
	{
		int size = n-i;
		index += k-1;
		if(index % size == 0) index = size;
		else index %= size;
		int next = get_next(0, leaf_size-1, 1, index, seg_tree);
		cout << next+1;
		if(i != n-1) cout << ", ";
		update(next+leaf_size, 0, seg_tree);
	}
	cout << '>';

	return 0;
}