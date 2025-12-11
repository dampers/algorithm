#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


int dp[105];

int top_down(int k)
{
    if(k <= 0) return 0;
    if(k <= 6) return k;

    if(dp[k] != -1) return dp[k];

    int ret = top_down(k-1) + 1;
    for(int i=1;i<=k-3;i++)
    {
        int curr = top_down(i) * (k-i-1);
        ret = max(ret, curr);
    }
    return dp[k] = ret;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    memset(dp, -1, sizeof(dp));

    cout << top_down(N);

    return 0;
}