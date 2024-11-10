#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    if(n < 3)
    {
        cout << n;
        return 0;
    }

    int lidx = 0, ridx = 0, start = 0;
    int ans = 1, cnt = 1, i;
    for(i=1;i<n;i++)
    {
        if(v[i] != v[lidx] && ridx == 0)
        {
            ridx = i;
        }
        else if(v[i] == v[lidx])
        {
            lidx = i;
        }
        else if(v[i] == v[ridx])
        {
            ridx = i;
        }
        else
        {
            // cout << lidx << ' ' << ridx << endl;
            if(lidx > ridx) swap(lidx, ridx);
            while(start <= lidx)
            {
                start++;
                cnt--;
            }
            lidx = ridx;
            ridx = i;

        }
        cnt += 1;
        // cout << cnt << endl;
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}