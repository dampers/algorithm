#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<int> seg_tree;

void update(int nodeNum, int value)
{
	seg_tree[nodeNum] += value;
	while(nodeNum > 1)
	{
		nodeNum /= 2;
		seg_tree[nodeNum] = seg_tree[nodeNum*2] + seg_tree[nodeNum*2+1];
	}
}

int find(int L, int R, int nodeNum, int value)
{
	if(L == R) return L;
	int mid = (L+R) / 2;
	if(value <= seg_tree[nodeNum*2]) return find(L, mid, nodeNum*2, value);
	return find(mid+1, R, nodeNum*2+1, value-seg_tree[nodeNum*2]);
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int depth = (int)ceil(log2(1000001)) + 1;
	int tree_size = 1 << depth;
	int leaf_size = tree_size >> 1;
	seg_tree.resize(tree_size, 0);

	int n;
	cin >> n;
	while(n--)
	{
		int a, b, c;
		cin >> a;
		if(a == 1)
		{
			cin >> b;
			int next = find(0, leaf_size-1, 1, b);
			cout << next << endl;
			update(next+leaf_size, -1);
		}
		else // a == 2
		{
			cin >> b >> c;
			update(b+leaf_size, c);
		}
	}

	return 0;
}