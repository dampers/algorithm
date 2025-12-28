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

    int N, M;
    cin >> N;
    vector<int> v0(N, 0);
    for(int i=0;i<N;i++)
        cin >> v0[i];
    cin >> M;
    vector<int> v1(M, 0);
    for(int i=0;i<M;i++)
        cin >> v1[i];

    vector<int> ans;
    int idx0 = 0, idx1 = 0;
    while(1)
    {
        bool flag = false;
        for(int32_t num=100;num>=1;num--)
        {
            int next0 = -1;
            int next1 = -1;
            for(int i=idx0;i<N;i++)
            {
                if(v0[i] == num)
                {
                    next0 = i;
                    break;
                }
            }
            for(int i=idx1;i<M;i++)
            {
                if(v1[i] == num)
                {
                    next1 = i;
                    break;
                }
            }
            if(next0 != -1 && next1 != -1)
            {
                ans.push_back(num);
                idx0 = next0+1;
                idx1 = next1+1;
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }

    cout << ans.size() << endl;
    for(auto K : ans) cout << K << ' ';
    
    return 0;
}