#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int chi[55][55];
bool hcheck[15];
vector<pair<int, int>> host;
vector<pair<int, int>> cho;
vector<pair<int ,int>> client;
int mn = 2555;
int n, m, hostsize, clientsize;

void dfs(int pos, int ind)
{
	if(pos==m)
	{
		int  cnt = 0;
		for(int i=0;i<clientsize;i++)
		{
			int y = client[i].first, x = client[i].second, tmn = 2555;
			for(int ii=0;ii<m;ii++)
			{
				int tmp = abs(cho[ii].first-y)+abs(cho[ii].second-x);
				if(tmp<tmn) tmn = tmp;
			}
			cnt += tmn;
		}
		if(mn>cnt) mn = cnt;
		return;
	}
	for(int i=ind;i<hostsize;i++)
	{
		if(!hcheck[i])
		{
			hcheck[i] = true;
			cho.push_back({host[i].first, host[i].second});
			dfs(pos+1, i+1);
			hcheck[i] = false;
			cho.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int ii=0;ii<n;ii++)
		{
			cin>>chi[i][ii];
			if(chi[i][ii]==1) client.push_back({i,ii});
			else if(chi[i][ii]==2) host.push_back({i,ii});
		}
	}
	hostsize = host.size();
	clientsize = client.size();
	dfs(0, 0);
	cout<<mn;
	return 0;
}