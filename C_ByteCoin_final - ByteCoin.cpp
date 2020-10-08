#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lld;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin>>n;
   vector<lld> dp(n+1, 5);
   for(int i=1;i*i<=n;i++)
      dp[i*i] = 1;
   if(dp[n]==1)
   {
      cout<<1;
      return 0;
   }
   for(int i=2;i<=n;i++)
   {
      for(int j=1;j*j<=i;j++)
      {
         int tmp = j*j;
         if(dp[i-tmp]<5) dp[i] = min(dp[i-tmp]+1, dp[i]);
      }
   }
   cout<<dp[n]<<endl;
   return 0;
}