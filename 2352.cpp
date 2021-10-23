#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int get_seg_cal(int L, int R, int node, int left, int right, vector<int>& seg_tree)
{
	if(L > right || R < left) return 0;
	if(L <= left && right <= R) return seg_tree[node];
	int mid = (left+right)/2;
	return max(get_seg_cal(L, R, node*2, left, mid, seg_tree),
		get_seg_cal(L, R, node*2+1, mid+1, right, seg_tree));
}

void update(int leaf_size, int nodeNum, int value, vector<int>& seg_tree)
{
	nodeNum += leaf_size;
	seg_tree[nodeNum] = value;
	while(nodeNum > 1)
	{
		nodeNum /= 2;
		seg_tree[nodeNum] = max(seg_tree[nodeNum*2], seg_tree[nodeNum*2+1]);
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<pii> v(n, {0, 0});
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());

	int depth = (int)ceil(log2(n))+1;
	int tree_size = 1 << depth;
	int leaf_size = tree_size/2;

	vector<int> seg_tree(tree_size, 0);

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int length = get_seg_cal(0, v[i].second, 1, 0, leaf_size-1, seg_tree);
		update(leaf_size, v[i].second, length+1, seg_tree);
		ans = max(ans, length+1);
	}
	cout << ans;
	return 0;
}