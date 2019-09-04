#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
bool check[1001];
vector<vector<int> > v(1001);

void dfs(int pos)
{
	int size = v[pos].size();
	for(int i=0;i<size;i++)
	{
		if(!check[v[pos][i]])
		{
			check[v[pos][i]] = true;
			cout<<v[pos][i]<<' ';
			dfs(v[pos][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, start;
	cin>>n>>m>>start;
	check[start] = true;
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(v[i].begin(), v[i].end());
	cout<<start<<' ';
	dfs(start);
	cout<<endl;
	memset(check, false, sizeof(check));
	check[start] = true;
	queue<int> q;
	cout<<start<<' ';
	q.push(start);
	while(!q.empty())
	{
		int ck = q.front();
		int size = v[ck].size();
		q.pop();
		for(int i=0;i<size;i++)
		{
			if(!check[v[ck][i]])
			{
				check[v[ck][i]] = true;
				q.push(v[ck][i]);
				cout<<v[ck][i]<<' ';
			}
		}
	}
	return 0;
}