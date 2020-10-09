#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[2][100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    memset(dp, 0, sizeof(dp));
    int n, ans = INT_MAX, sumB = 0;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        sumB += y;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=100000;j++)
        {
            if (j<v[i].first) dp[i%2][j] = dp[(i-1)%2][j];
            else dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-v[i].first] + v[i].second);
            ans = min(ans, max(j, sumB - dp[i % 2][j]));
        }
    }   
    cout<<ans;

    return 0;
}