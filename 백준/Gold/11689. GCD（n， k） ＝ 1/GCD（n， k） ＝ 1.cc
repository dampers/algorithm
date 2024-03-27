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

bool prime[1000001];

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    int ans = n;
    int sqn = sqrt(n);
    for (int i = 2; i <= sqn; i++)
    {
        if (n % i == 0)
        {
            ans -= ans / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ans -= ans / n;

    cout << ans;
    return 0;
}