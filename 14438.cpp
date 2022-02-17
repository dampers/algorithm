#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int getCal(int L, int R, int left, int right, int nodeNum, vector<int>& seg_tree)
{
	if(L > right || R < left) return INT_MAX;
	if(L <= left && right <= R) return seg_tree[nodeNum];
	int mid = (left+right)/2;
	return min(getCal(L, R, left, mid, nodeNum*2, seg_tree), getCal(L, R, mid+1, right, nodeNum*2+1, seg_tree));

}

void update(int nodeNum, int value, int leaf_size, vector<int>& seg_tree)
{
	nodeNum += leaf_size;
	seg_tree[nodeNum] = value;
	while(nodeNum > 1)
	{
		nodeNum /= 2;
		seg_tree[nodeNum] = min(seg_tree[nodeNum*2], seg_tree[nodeNum*2+1]);
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int depth = (int)ceil(log2(n));
	int tree_size = 1 << (depth+1);
	vector<int> seg_tree(tree_size, INT_MAX);
	int leaf_size = tree_size/2;
	

	for(int i=0;i<n;i++)
	{
		cin >> seg_tree[i+leaf_size];
	}
	for(int i=leaf_size-1;i>0;i--)
	{
		seg_tree[i] = min(seg_tree[i*2], seg_tree[i*2+1]);
	}

	int m, a, b, c;
	cin >> m;
	while(m--)
	{
		cin >> a >> b >> c;
		if(a == 1) update(b-1, c, leaf_size, seg_tree);
		if(a == 2) cout << getCal(b-1, c-1, 0, leaf_size-1, 1, seg_tree) << endl;
	}
	return 0;
}
