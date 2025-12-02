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

int goalr, goalg, goalb;

bool checkv[33];
int recurr(int pos, int k, vector<pair<int, pair<int, int>>>& v)
{
    int ret = 1e9;
    if(pos <= 7 && pos > 1)
    {
        int tr = 0, tg = 0, tb = 0;
        for(size_t i=0;i<v.size();i++)
        {
            if(checkv[i])
            {
                tr += v[i].first;
                tg += v[i].second.first;
                tb += v[i].second.second;
            }
        }
        tr /= pos;
        tg /= pos;
        tb /= pos;
        ret = min(ret, abs(tr-goalr) + abs(tg-goalg) + abs(tb-goalb));
    }
    if(pos > 7) return ret;

    for(size_t i=k;i<v.size();i++)
    {
        if(checkv[i] == false)
        {
            checkv[i] = true;
            ret = min(ret, recurr(pos+1, i+1, v));
            checkv[i] = false;
        }
    }
    return ret;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> v(N);

    for(int i=0;i<N;i++)
    {
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    }
    cin >> goalr >> goalg >> goalb;

    cout << recurr(0, 0, v);



    return 0;
}