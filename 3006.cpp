#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int seg_tree[400004];
int n, leaf_size;
int get_seg_cal(int L, int R, int node, int left, int right)
{
	if(L > right || R < left) return 0;
	if(L <= left && right <= R) return seg_tree[node];
	int mid = (left+right)/2;
	return get_seg_cal(L, R, node*2, left, mid) + get_seg_cal(L, R, node*2+1, mid+1, right);
}

void update(int nodeNum, int value)
{
	seg_tree[nodeNum] = value;
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
	leaf_size = tree_size / 2;
	// constrct
	for(int i=0;i<n;i++)
		seg_tree[i+leaf_size] = 1;
	for(int i=leaf_size-1;i>=1;i--)
		seg_tree[i] = seg_tree[i*2] + seg_tree[i*2+1];

	int tsize = n/2;
	for(int i=0;i<tsize;i++)
	{
		update(v[i].second+leaf_size, 0);
		int curr = get_seg_cal(0, v[i].second, 1, 0, leaf_size-1);
		cout << curr << endl;
		update(v[n-i-1].second+leaf_size, 0);
		curr = get_seg_cal(v[n-i-1].second, leaf_size-1, 1, 0, leaf_size-1);
		cout << curr << endl;
	}
	if(n%2) cout << 0 << endl;

	return 0;
}