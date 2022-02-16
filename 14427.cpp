#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, tree_size, leaf_size;
vector<pii> seg_tree;

void update(int nodeNum, int value)
{
	nodeNum += leaf_size;
	seg_tree[nodeNum].first = value;
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

	cin >> N;
	int depth = (int)ceil(log2(N));
	tree_size = 1<<(depth+1);
	leaf_size = tree_size/2;
	int last_node = leaf_size-1;

	seg_tree.resize(tree_size, {INT_MAX, 0});

	for(int i=0;i<N;i++)
	{
		cin >> seg_tree[i+leaf_size].first;
		seg_tree[i+leaf_size].second = i+1;
	}
	for(int i=last_node;i>0;i--)
	{
		seg_tree[i] = min(seg_tree[i*2], seg_tree[i*2+1]);
	}
	int m, a, b, c;
	cin >> m;
	while(m--)
	{
		cin >> a;
		if(a == 1)
		{
			cin >> b >> c;
			update(b-1, c);
		}
		else
		{
			cout << seg_tree[1].second << endl;
		}
	}


	return 0;
}
