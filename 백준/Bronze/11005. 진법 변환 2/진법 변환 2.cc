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

    int N, B;
    cin >> N >> B;

    string s = "";
    while(N)
    {
        if(N % B < 10) s += '0' + N % B;
        else s += 'A' + (N % B - 10);
        N /= B;
    }
    reverse(s.begin(), s.end());
    cout << s ;

    return 0;
}