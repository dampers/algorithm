#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int weight[101], value[101];
int dp[101][100001];
int n, k;
int cnt;
int top_down(int pos, int w, int v)
{
	cnt++;
	if(pos==n) return 0;
	if(dp[pos][w]!=-1) return dp[pos][w];
	if(weight[pos]+w<=k)
		return dp[pos][w] = max(top_down(pos+1, weight[pos]+w, v+value[pos])+value[pos], top_down(pos+1, w, v));
	return dp[pos][w] = top_down(pos+1, w, v);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>weight[i]>>value[i];
	memset(dp, -1, sizeof(dp));
	cout<<top_down(0, 0, 0);
	return 0;
}