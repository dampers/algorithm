#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	
	vector<int> dp(s.length()+1, INT_MIN);
    if(s[0] == '+') dp[0] = 10;
    if(s[0] == '-') dp[0] = 1;
    if(s.length() > 1 && s[0] == '+' && s[1] == '-') dp[1] = 11;
    for(size_t i=2;i<s.length();i++)
    {
        if(s[i-1] == '+' && s[i] == '-') dp[i] = max(dp[i], dp[i-2]+1);
        if(s[i-1] == '+' && s[i] == '+') dp[i] = max(dp[i], dp[i-2]+10);
        if(s[i-1] == '-' && s[i] == '-') dp[i] = max(dp[i], dp[i-2]-1);
        if(s[i-1] == '-' && s[i] == '+') dp[i] = max(dp[i], dp[i-2]-10);
        if(i>2 && s[i-2]=='+' && s[i-1]=='+' && s[i]=='-')
            dp[i] = max(dp[i], dp[i-3]+11);
        if(i>2 && s[i-2]=='-' && s[i-1]=='+' && s[i] =='-')
            dp[i] = max(dp[i], dp[i-3]-11);
    }
    int len = s.length();
    cout << dp[len-1];
	
	return 0;
}
