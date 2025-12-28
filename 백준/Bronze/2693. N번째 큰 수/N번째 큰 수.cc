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



int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T-- > 0)
    {
        vector<int> v(10, 0);
        for(int i=0;i<10;i++) cin >> v[i];
        sort(v.begin(), v.end());
        cout << v[7] << endl;
    }


    return 0;
}