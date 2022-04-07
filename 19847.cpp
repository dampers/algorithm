#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

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
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ansv(v[0], 1);
    int curr = v[0];
    for (int i = 1; i < n; i++)
    {
        if (curr > v[i])
        {
            int p = curr / v[i] - 1, m = curr % v[i];
            for (int j = v[i]; j < curr; j++)
                ansv[j % v[i]] += ansv[j];
            curr = v[i];
        }
    }
    cout.precision(11);
    cout << fixed;
    int sum = 0;
    for (int i = 0; i < curr; i++)
        sum += ansv[i] * i;
    double ans = sum / (double)v[0];
    cout << ans;

    return 0;
}
