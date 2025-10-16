#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const double EPS = 1e-9;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int pnums[7];

void recurr(int pos, int curr, vector<string>& vs, int& cnt)
{
    if(pos == 7)
    {
        queue<int> q;
        int qcnt = 1;
        q.push(pnums[0]);
        vector<int> checkv(7, 0);
        checkv[0] = 1;

        while(!q.empty())
        {
            int cnum = q.front();
            q.pop();
            int y = cnum / 5;
            int x = cnum % 5;
            for(int i=0;i<4;i++)
            {
                int ny = y+dy[i];
                int nx = x+dx[i];
                int next = ny * 5 + nx;
                if(ny >= 5 || nx >= 5 || ny < 0 || nx < 0) continue;
                for(int j=1;j<7;j++)
                {
                    if(checkv[j] == 0 && pnums[j] == next)
                    {
                        checkv[j] = 1;
                        qcnt++;
                        q.push(pnums[j]);
                    }
                }
            }
        }
        if(qcnt == 7)
        {
            int ysum = 0, ssum = 0;
            for(int i=0;i<7;i++)
            {
                int y = pnums[i] / 5;
                int x = pnums[i] % 5;
                ysum += vs[y][x]=='Y'?1:0;
                ssum += vs[y][x]=='S'?1:0;
            }
            if(ssum > 3) cnt++;
        }

        return;
    }
    for(int i=curr;i<25;i++)
    {
        pnums[pos] = i;
        recurr(pos+1, i+1, vs, cnt);
    }
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<string> vs(5);
    for(int i=0;i<5;i++)
    {
        cin >> vs[i];
    }
    int ans = 0;
    recurr(0, 0, vs, ans);
    cout << ans;
	
 	return 0;
}