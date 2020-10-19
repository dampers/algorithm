#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[10001];

int longest;
int mx;

int dfs(int pos, vector<vector<pair<int, int>>>& v, int cost)
{
	check[pos] = true;
	int ret = cost, cnt = 0;
	for(int i=0;i<v[pos].size();i++)
	{
		if(!check[v[pos][i].first])
		{
			cnt++;
			ret = max(ret, dfs(v[pos][i].first, v, cost+v[pos][i].second));
		}
	}
	if(cnt==0 && mx<ret)
	{
		mx = ret;
		longest = pos;
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin>>n;
	vector<vector<pair<int, int>>> v(n+1);
	for(int i=0;i<n-1;i++)
	{
		int p, s, c;
		cin>>p>>s>>c;
		v[p].push_back({s, c});
		v[s].push_back({p, c});
	}
	dfs(1, v, 0);
	memset(check, false, sizeof(check));
	cout<<dfs(longest, v, 0);
	return 0;
}