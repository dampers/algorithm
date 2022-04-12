#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n;

int adds(int a, int b)
{
    return stoll(to_string(a)+to_string(b));
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> n;
	
	vector<bool> prime(2000001, true);
	prime[0] = prime[1] = false;
	for(int i=2;i<2000001;i++)
	{
	    if(!prime[i]) continue;
	    for(int j=i+i;j<2000001;j+=i)
	        prime[j] = false;
	}
	
	vector<vector<int>> dp(n+5, vector<int>(n+5, 0));
    dp[1][1] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ltmp = adds(i+1, j), rtmp = adds(i, j+1);
            if(i < n)
            {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]+prime[ltmp]);
            }
            if(j < n)
            {
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]+prime[rtmp]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout <<i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    */
    cout << dp[n][n]-1;
	
	return 0;
}
