#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int dp[1003][3], rgb[1003][3];

int f(int n, int k)
{
    if(dp[n][k]) return dp[n][k];
    if(n==0) return rgb[0][k];
    if(k==1) return dp[n][1] = min(f(n-1, 0),f(n-1, 2))+rgb[n][1];
    else if(k==2) return dp[n][2] = min(f(n-1, 0), f(n-1, 1))+rgb[n][2];
    else return dp[n][0] = min(f(n-1, 1), f(n-1, 2))+rgb[n][0];
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];
    cout<<min(f(n, 0), min(f(n, 1), f(n, 2)));
    return 0;
}