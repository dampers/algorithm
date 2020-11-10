#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int init(vector<int>& v, vector<int>& tree, int start, int end, int node, bool flag)
{
	if(start==end) return tree[node] = v[start];
	int mid = (start+end)/2;
	if(flag)
		return tree[node] = max(init(v, tree, start, mid, node*2, flag), init(v, tree, mid+1, end, node*2+1, flag));
	return tree[node] = min(init(v, tree, start, mid, node*2, flag), init(v, tree, mid+1, end, node*2+1, flag));
}

int find(vector<int>& tree, int node, int start, int end, int left, int right, bool flag)
{
	if(left>end || right<start)
	{
		if(flag) return 0;
		else return (int)1e9;
	}
	if(left<=start && end<=right) return tree[node];
	int mid = (start+end)/2;
	if(flag)
		return max(find(tree, node*2, start, mid, left, right, flag), find(tree, node*2+1, mid+1, end, left, right, flag));
	return min(find(tree, node*2, start, mid, left, right, flag), find(tree, node*2+1, mid+1, end, left, right, flag));
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int h = (int)ceil(log2(n)), tsize = 1<<(h+1);
	vector<int> v(n);
	vector<int> stree(tsize), btree(tsize);
	for(int i=0;i<n;i++)
		cin>>v[i];
	init(v, stree, 0, n-1, 1, false);
	init(v, btree, 0, n-1, 1, true);
	while(m--)
	{
		int a, b;
		cin>>a>>b;
		cout<<find(stree, 1, 0, n-1, a-1, b-1, false)<<' '<<find(btree, 1, 0, n-1, a-1, b-1, true)<<endl;
	}
	return 0;
}