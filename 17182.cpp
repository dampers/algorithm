#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int dp[12][(1<<12)], cost[12][12];
int n, k;
int tsp(int pos, int visit)
{
	int& ret = dp[pos][visit];
	if(ret!=INT_MAX) return ret;
	if(visit==(1<<n)-1) return 0;
	ret = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(visit & (1<<i)) continue;
		ret = min(ret, tsp(i, visit|(1<<i))+cost[pos][i]);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			dp[i][j] = INT_MAX;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>cost[i][j];
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cost[i][j] = min(cost[i][k]+cost[k][j], cost[i][j]);
	cout<<tsp(k, (1<<k));
	return 0;
}