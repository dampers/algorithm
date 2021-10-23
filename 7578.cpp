#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void update(int nodeNum, int value, vector<int>& seg_tree)
{
	seg_tree[nodeNum] = value;
	while(nodeNum > 1)
	{
		nodeNum /= 2;
		seg_tree[nodeNum] = seg_tree[nodeNum*2] + seg_tree[nodeNum*2+1];
	}
}

int get_seg_cal(int find_L, int find_R, int nodeNum, int left, int right, vector<int>& seg_tree)
{
	if(find_L > right || find_R < left) return 0;
	if(find_L <= left && right <= find_R) return seg_tree[nodeNum];
	int mid = (left+right)/2;
	return get_seg_cal(find_L, find_R, nodeNum*2, left, mid, seg_tree) + get_seg_cal(find_L, find_R, nodeNum*2+1, mid+1, right, seg_tree);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<int> v(n, 0), b(1000005, 0);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		b[tmp] = i;
	}

	int depth = (int)ceil(log2(n))+1;
	int tree_size = 1 << depth;
	int leaf_size = tree_size/2;
	vector<int> seg_tree(tree_size, 0);

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int bindex = b[v[i]];
		int crossed = get_seg_cal(bindex, leaf_size-1, 1, 0, leaf_size-1, seg_tree);
		ans += crossed;
		//cout << v[i] << ' ' << bindex << ' ' << crossed << endl;
		update(bindex+leaf_size, 1, seg_tree);
	}
	cout << ans << endl;


	return 0;
}