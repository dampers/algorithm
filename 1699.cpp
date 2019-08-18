#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int dp[100005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	clock_t start, end;
	start = clock();
	int n;
	cin>>n;
	for(int i=1;i*i<=100000;i++)
		dp[i*i] = 1;
	dp[2] = 2;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;i+j<=n;j++)
		{
			if(dp[i+j]==0) dp[i+j] = dp[i]+dp[j];
			else if(dp[i+j]>dp[i]+dp[j]) dp[i+j] = dp[i]+dp[j];
		}
	}
	cout<<dp[n];
	end = clock();
	double time = (double)(end-start)/CLOCKS_PER_SEC;
	cout<<"finished at: "<< time;
	return 0;
}