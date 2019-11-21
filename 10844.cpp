#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld dp[101][10];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=9;i++) dp[1][i] = 1;
	lld sum = 0LL;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(j==0) dp[i+1][1] += dp[i][0]%1000000000;
			else if(j==9) dp[i+1][8] += dp[i][9]%1000000000;
			else
			{
				dp[i+1][j-1] += dp[i][j]%1000000000;
				dp[i+1][j+1] += dp[i][j]%1000000000;
			}
		}
	}
	for(int i=0;i<=9;i++)
		sum = (sum+dp[n][i])%1000000000;
	cout<<sum;
	return 0;
}