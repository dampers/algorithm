#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

lld init(vector<lld>& list, vector<lld>& tree, int node, int start, int end)
{
	if(start==end) return tree[node] = list[start];
	int mid = (start+end)/2;
	return tree[node] = init(list, tree, node*2, start, mid)+init(list, tree, node*2+1, mid+1, end);
}

void update(vector<lld>& tree, int node, int start, int end, int index, lld dif)
{
	if(index<start || index>end) return;
	tree[node] += dif;
	if(start!=end)
	{
		int mid = (start+end)/2;
		update(tree, node*2, start, mid, index, dif);
		update(tree, node*2+1, mid+1, end, index, dif);
	}
}

lld sum(vector<lld>& tree, int node, int start, int end, int left, int right)
{
	if(left>end || right<start) return 0LL;
	if(left<=start && end<=right) return tree[node];
	int mid = (start+end)/2;
	return sum(tree, node*2, start, mid, left, right)+sum(tree, node*2+1, mid+1, end, left, right);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin>>n>>m;
	int height = (int)ceil(log2(n)), tree_size = (1<<(height+1));
	vector<lld> v(n, 0), tree(tree_size, 0);
	init(v, tree, 1, 0, n-1);
	while(m--)
	{
		lld a, b, c;
		cin>>a>>b>>c;
		if(a)
		{
			update(tree, 1, 0, n-1, b-1, c-v[b-1]);
			v[b-1] = c;
		}
		else // a==0
		{
			if(b>c) swap(b, c);
			cout<<sum(tree, 1, 0, n-1, b-1, c-1)<<endl;
		}
	}
	return 0;
}