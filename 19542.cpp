#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int check[100005];
int dep[100005];
int s, d, cnt;
vector<vector<int>> v(100005);
vector<pair<int, int>> leaf;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first>b.first;
}

void dfs(int pos, int k)
{
	dep[k] = pos;
	check[k] = 1;
	for(int i=0;i<(int)v[k].size();i++)
	{
		if(check[v[k][i]]) continue;
		dfs(pos+1, v[k][i]);
	}
	if(v[k].size()==1 && k != s)
		leaf.push_back({pos, k});
}

void back(int pos, int k)
{
	if(pos>=d)
	{
		check[k] = -1;
		for(int i=0;i<(int)v[k].size();i++)
		{
			if(dep[v[k][i]]<dep[k])
			{
				if(check[v[k][i]]) continue;
				back(pos+1, v[k][i]);
			}
		}
		return ;
	}
	check[k] = 1;
	for(int i=0;i<(int)v[k].size();i++)
	{
		if(check[v[k][i]] || dep[k]<dep[v[k][i]]) continue;
		back(pos+1, v[k][i]);
	}

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n>>s>>d;
	for(int i=0;i<n-1;i++)
	{
		int x, y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0, s);
	memset(check, 0, sizeof(check));
	sort(leaf.begin(), leaf.end(), comp);
	for(int i=0;i<(int)leaf.size();i++)
		back(0, leaf[i].second);
	for(int i=1;i<=n;i++)
		if(check[i]==-1) cnt++;		
	cout<<((cnt-1)*2>0?(cnt-1)*2:0);
	return 0;
}