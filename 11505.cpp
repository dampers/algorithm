#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define MOD 1000000007
typedef long long lld;

lld v[1000001], tree[4000001];

lld init(int node, int start, int end)
{
	if(start==end) return tree[node] = v[start];
	int mid = (start+end)/2;
	return tree[node] = (init(node*2, start, mid)*init(node*2+1, mid+1, end))%MOD;
}

lld update(int node, int start, int end, int index, lld change)
{
	if(index<start || index>end) return tree[node];
	// start <= index <= end
	if(start==end) return tree[node] = change;
	int mid = (start+end)/2;
	return tree[node] = (update(node*2, start, mid, index, change)*update(node*2+1, mid+1, end, index, change))%MOD;
}

lld multiple(int node, int start, int end, int left, int right)
{
	if(end<left || start>right) return 1LL;
	if(left<=start && end<=right) return tree[node];
	int mid = (start+end)/2;
	return (multiple(node*2, start, mid, left, right)*multiple(node*2+1, mid+1, end, left, right))%MOD;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>v[i];
	init(1, 0, n-1);
	m += k;
	while(m--)
	{
		lld a, b, c;
		cin>>a>>b>>c;
		if(a==1)
		{
			update(1, 0, n-1, b-1, c);
			v[b-1] = c;
		}
		else // a==2
		{
			cout<<multiple(1, 0, n-1, b-1, c-1)<<endl;
		}
	}
	return 0;
}