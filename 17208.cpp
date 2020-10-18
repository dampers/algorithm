#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int dp[105][305][305];
int corder[105], forder[105];
int n;
int top_down(int pos, int m, int k)
{
	int& ret = dp[pos][m][k];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=pos+1;i<=n;i++)
	{
		if(corder[i]<=m && forder[i]<=k)
			ret = max(ret, top_down(i, m-corder[i], k-forder[i])+1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, k;
	cin>>n>>m>>k;
	memset(dp, -1, sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>corder[i]>>forder[i];
	cout<<top_down(0, m, k);
	return 0;
}