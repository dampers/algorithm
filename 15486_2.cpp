#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
   ios_base::sync_with_stdio(NULL);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin>>n;
   vector<int> t(n), p(n), dp(n+1, 0);
   for(int i=0;i<n;i++)
   {
      cin>>t[i]>>p[i];
   }
   p.push_back(0);
   for(int i=n-1;i>=0;i--)
   {
      if(i+t[i]>n) dp[i] = dp[i+1];
      else dp[i] = max(dp[i+1], p[i]+dp[i+t[i]]);
   }
   cout<<dp[0];
   return 0;
}