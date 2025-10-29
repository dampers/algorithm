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

int N;
int cnt;

bool recurr(int pos, int curr, int last, int len)
{
    bool ret = false;
    if(pos == len)
    {
        if(N == cnt)
        {
            cout << curr << endl;
            ret = true;
        }
        cnt++;
        return ret;
    }
    for(int i=0;i<last;i++)
    {
        if(i < last)
        {
            ret |= recurr(pos+1, curr*10+i, i, len);
        }
    }
    return ret;
}


int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    bool ret = false;
    for(int i=1;i<12;i++)
    {
        ret |= recurr(0, 0, 10, i);
    }
    if(!ret) cout << -1 << endl;


    return 0;
}