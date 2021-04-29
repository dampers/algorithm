#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int parent[55];

int find(int v)
{
	if(parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if(u == v) return;
	if(u > v) parent[u] = v;
	else parent[v] = u;
}

void init()
{
	for(int i=1;i<55;i++)
		parent[i] = i;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	init();

	int n, m, c;
	cin >> n >> m >> c;
	vector<int> known(c, 0);
	int ans = m;
	for(int i=0;i<c;i++)
	{
		cin >> known[i];
		parent[known[i]] = 0;
	}
	vector<vector<int>> party(m,vector<int>());
	for(int i=0;i<m;i++)
	{
		int k, first, tmp;
		cin >> k;
		party[i].resize(k);
		if(k == 0) continue;
		cin >> first;
		first = find(first);
		party[i][0] = first;
		for(int j=1;j<k;j++)
		{
			cin >> tmp;
			merge(tmp, first);
			party[i][j] = first = find(tmp);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<party[i].size();j++)
		{
			if(find(party[i][j]) == 0)
			{
				ans--;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}