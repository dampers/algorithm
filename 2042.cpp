#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld init(vector<lld> &arr, vector<lld> &tree, int node, int start, int end)
{
	if(start==end) return tree[node] = arr[start];
	int mid = (start+end)/2;
	return tree[node] = init(arr, tree, node*2, start, mid) + init(arr, tree, node*2+1, mid+1, end);
}

void update(vector<lld> &tree, int node, int start, int end, int index, lld dif)
{
	if(!(start <= index && index <= end)) return;
	tree[node] += dif;
	if(start!=end)
	{
		int mid = (start+end)/2;
		update(tree, node*2, start, mid, index, dif);
		update(tree, node*2, mid+1, end, index, dif);
	}
}

lld sum(vector<lld> &tree, int node, int start, int end, int left, int right)
{
	if(left > end || right < start) return 0;
	if(left <= start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;
	int h = (int)ceil(log2(n));
	int tree_size = (1<<(h+1));
	vector<lld> arr(n);
	vector<lld> tree(tree_size);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	init(arr, tree, 1, 0, n-1);
	m += k;
	while(m--)
	{
		int sg;
		cin>>sg;
		if(sg==1)
		{
			int pos;
			lld val;
			cin>>pos>>val;
			lld dif = val-arr[pos-1];
			arr[pos-1] = val;
			update(tree, 1, 0, n-1, pos-1, dif);
		}
		else if(sg==2)
		{
			int l, r;
			cin>>l>>r;
			cout<<sum(tree, 1, 0, n-1, l-1, r-1)<<endl;
		}
	}
	
	return 0;
}