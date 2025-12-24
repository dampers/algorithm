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

int N, D;

int recursive(int pos, int curr, vector<pair<int, pair<int, int>>>& v)
{
    int ret = (D - curr);
    if(pos == N)
    {
        return ret;
    }
    if(curr <= v[pos].first && v[pos].second.first <= D) ret = min(ret, (v[pos].first-curr) + recursive(pos+1, v[pos].second.first, v) + v[pos].second.second);
    ret = min(ret, recursive(pos+1, curr, v));
    return ret;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    vector<pair<int, pair<int, int>>> v(N);
    for(int i=0;i<N;i++)
    {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    sort(v.begin(), v.end());

    cout << recursive(0, 0, v);



    return 0;
}