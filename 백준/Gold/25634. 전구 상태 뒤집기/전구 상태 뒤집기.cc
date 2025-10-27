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


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> a(N+1, 0), b(N+1, 0);
    vector<int> psum(N+1, 0);
    int cur = 0;
    for(int i=1;i<=N;i++) cin >> a[i];
    for(int i=1;i<=N;i++)
    {
        cin >> b[i];
        if(b[i])
        {
            cur += a[i];
            psum[i] = psum[i-1] - a[i];
        }
        else psum[i] = psum[i-1] + a[i];
    }
    int mx = psum[1];
    int left = 0;
    for(int i=1;i<=N;i++)
    {
        mx = max(mx, psum[i]-psum[left]);
        if(psum[left] > psum[i]) left = i;
    }
    cur += mx;
    cout << cur << endl;
    return 0;
}