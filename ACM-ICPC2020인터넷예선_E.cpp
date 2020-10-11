#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int parent[500005];
int flag;

int find(int n)
{
	if(parent[n]==n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int v, int u, int i)
{
	v = find(v);
	u = find(u);
	if(v==u)
	{
		if(flag==0) flag = i;
		return;
	}
	parent[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n);
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		merge(a, b, i+1);
	}
	cout<<flag;
	return 0;
}