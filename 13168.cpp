#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld cost[101][101], ncost[101][101];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			if(i==j) continue;
			cost[i][j] = 1000000000;
			ncost[i][j] = 1000000000;
		}
	}
	int n, r;
	cin>>n>>r;
	map<string, int> mp;
	string city;
	for(int i=0;i<n;i++)
	{
		cin>>city;
		//cout<<city<<endl;
		mp[city] = i;
	}
	int m, k;
	cin>>m;
	vector<int> route(k);
	for(int i=0;i<m;i++)
	{
		cin>>city;
		route[i] = mp[city];
	}
	cin>>k;
	string veh, dest;
	int tcost;
	for(int i=0;i<k;i++)
	{
		cin>>veh>>city>>dest>>tcost;
		int s = mp[city], e = mp[dest];
		if(veh=="Mugunghwa" || veh=="ITX-Saemaeul" || veh=="ITX-Cheongchun")
		{
			ncost[s][e] = 0;
			ncost[e][s] = 0;
		}
		else if(veh=="S-Train" || veh=="V-Train")
		{
			if(ncost[s][e]>tcost/2) 
			{
				ncost[s][e] = tcost/2;
				ncost[e][s] = tcost/2;
			}
		}
		else if(ncost[s][e]>tcost)
		{
			ncost[s][e] = tcost;
			ncost[e][s] = tcost;
		}
		if(cost[s][e]>tcost)
		{
			cost[s][e] = tcost;
			cost[e][s] = tcost;
		}
	}

	for(int h=0;h<n;h++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(cost[i][j]>cost[i][h]+cost[h][j])
				{
					cost[i][j] = cost[i][h]+cost[h][j];
					cost[j][i] = cost[i][j];
				}
			}
		}
	}

	for(int h=0;h<n;h++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(ncost[i][j]>ncost[i][h]+ncost[h][j])
				{
					ncost[i][j] = ncost[i][h]+ncost[h][j];
					ncost[j][i] = ncost[i][j];
				}
			}
		}
	}
	lld csum = 0LL, nsum = r;

	for(int i=1;i<m;i++)
	{
		csum += cost[route[i-1]][route[i]];
		nsum += ncost[route[i-1]][route[i]];
	}
	//cout<<csum<<' '<<nsum<<endl;
	if(csum<=nsum) cout<<"No";
	else cout<<"Yes";
	return 0;
}