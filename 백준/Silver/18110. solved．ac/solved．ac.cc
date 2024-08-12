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

int get_cutsize(int K)
{
    K *= 3;
    return (K / 20) + ((K%20)>=10?1:0);
}

int rounds(int a, int b)
{
    if(b == 0) return a;
    return (a/b) + ((a%b)>=(b/2+(b&1))?1:0);
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vi v(n, 0);
    for(int i=0;i<n;i++)
        cin >> v[i];
    int cs = get_cutsize(n);
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=cs;i<n-cs;i++)
    {
        ans += v[i];
    }
    cout << rounds(ans, n-cs-cs);

    return 0;
}