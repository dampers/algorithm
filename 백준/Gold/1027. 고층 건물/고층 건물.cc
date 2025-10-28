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

bool f(int x0, int y0, int x1, int y1, int x2, int y2)
{
    return (y1-y0)*x2 - (x1-x0)*y2 - (x0*y1 - x1*y0) > 0;
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    int mx = 0;
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
    }

    for(int curr=0;curr<N;curr++)
    {
        int curr_cnt = 0;
        for(int left=curr-1;left>=0;left--)
        {
            bool nobuildings = true;
            int checkbuild = left + 1;
            while(checkbuild < curr)
            {
                nobuildings &= f(left, v[left], curr, v[curr], checkbuild, v[checkbuild]);
                if(!nobuildings) break;
                checkbuild++;
            }
            if(nobuildings) curr_cnt++;
        }

        for(int right=curr+1;right<N;right++)
        {
            bool nobuildings = true;
            int checkbuild = right - 1;
            while(checkbuild > curr)
            {
                nobuildings &= f(curr, v[curr], right, v[right], checkbuild, v[checkbuild]);
                if(!nobuildings) break;
                checkbuild--;
            }
            if(nobuildings) curr_cnt++;
        }
        mx = max(mx, curr_cnt);
        // cout << curr << " " << curr_cnt << endl;
    }
    cout << mx << endl;


    return 0;
}