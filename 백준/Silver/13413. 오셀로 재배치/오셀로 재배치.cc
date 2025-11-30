#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


void solve()
{
    int N;
    cin >> N;
    string curr, goal;
    cin >> curr;
    cin >> goal;
    int wrongW = 0, wrongB = 0;
    for(int i=0;i<N;i++)
    {
        if(curr[i] != goal[i])
        {
            if(curr[i] == 'W') wrongW++;
            else wrongB++;
        }
    }
    int mn = min(wrongB, wrongW);
    int mx = max(wrongB, wrongW);
    cout << mn + (mx-mn) << endl;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T-- > 0) solve();

    return 0;
}