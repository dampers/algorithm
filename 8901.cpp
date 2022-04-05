#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ab, bc, ca;
    cin >> ab >> bc >> ca;
    
    int ans = 0;
    /*
    for(int i=0;i<=a;i++)
    {
        int tmp_ab = min(i, b);
        int tmp_ca = min(a-i, c);
        int tmp_bc = min((b-tmp_ab>0?b-tmp_ab:0), (c-tmp_ca>0?c-tmp_ca:0));
        ans = max(ans, ab*tmp_ab +ca*tmp_ca + bc*tmp_bc);
    }
    */
    
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=c;j++)
        {
            int tmp_ab = min(i, b);
            int tmp_ca = min(a-i, j);
            int tmp_bc = min(b-tmp_ab>0?b-tmp_ab:0, c-j);
            ans = max(ans, ab*tmp_ab +ca*tmp_ca + bc*tmp_bc);
        }
    }
    
    cout << ans << endl;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc-- > 0)
    {
        solve();
    }

	return 0;
}