#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pii> v(n);
	for(int i=0;i<n;i++)
	{
	    cin >> v[i].first >> v[i].second;
	}
	
	string tmp = "";
	for(int i=0;i<6;i++)
	    tmp.push_back('.');
	vector<string> vs(6, tmp);
	vs[2][2] = vs[3][3] = 'W';
	vs[2][3] = vs[3][2] = 'B';
	
	bool rels = false; // false == Black, True == White
	for(int i=0;i<n;i++)
	{
	    int y = v[i].first-1, x = v[i].second-1;
	    //cout << "y = " << y << ' ' << "x = " << x << endl;
	    if(!rels)
	    {
	        bool black = false;
	        for(int d=0;d<8;d++)
	        {
	            int ny = y+dy[d], nx = x+dx[d];
	            if(ny >= 6 || nx >= 6 || ny < 0 || nx < 0) continue;
	            if(vs[ny][nx] == 'W')
	            {
	                int ty = ny, tx = nx;
	                bool out_of_bound = false;
	                //cout << ty << ' ' << tx << ' ' << vs[ty][tx] << endl;
	                while(vs[ty][tx] == 'W')
	                {
	                    ty += dy[d];
	                    tx += dx[d];
	                    if(ty >= 6 || tx >= 6 || ty < 0 || tx < 0)
	                    {
	                        out_of_bound = true;
	                        break;
	                    }
	                }
	                
	                if(out_of_bound) continue;
	                if(vs[ty][tx] == 'B')
	                {
	                    int tty = ny, ttx = nx;
	                    while(vs[tty][ttx] == 'W')
    	                {
    	                    vs[tty][ttx] = 'B';
    	                    tty += dy[d];
    	                    ttx += dx[d];
    	                }
    	                black = true;
	                }
	            }
	        }
	        if(black) vs[y][x] = 'B';
	    }
	    else
	    {
	        bool white = false;
	        for(int d=0;d<8;d++)
	        {
	            int ny = y+dy[d], nx = x+dx[d];
	            if(ny >= 6 || nx >= 6 || ny < 0 || nx < 0) continue;
	            if(vs[ny][nx] == 'B')
	            {
	                int ty = ny, tx = nx;
	                bool out_of_bound = false;
	                while(vs[ty][tx] == 'B')
	                {
	                    ty += dy[d];
	                    tx += dx[d];
	                    if(ty >= 6 || tx >= 6 || ty < 0 || tx < 0)
	                    {
	                        out_of_bound = true;
	                        break;
	                    }
	                }
	                if(out_of_bound) continue;
	                if(vs[ty][tx] == 'W')
	                {
	                    int tty = ny, ttx = nx;
	                    while(vs[tty][ttx] == 'B')
    	                {
    	                    vs[tty][ttx] = 'W';
    	                    tty += dy[d];
    	                    ttx += dx[d];
    	                }
    	                white = true;
	                }
	            }
	        }
	        if(white) vs[y][x] = 'W';
	    }
	    rels = !rels;
	}
	
	
	for(int i=0;i<6;i++)
    {
        cout << vs[i] << endl;
    }
    int wcnt = 0, bcnt = 0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(vs[i][j] == 'B') bcnt++;
            if(vs[i][j] == 'W') wcnt++;
        }
    }
    if(bcnt > wcnt) cout << "Black\n";
    else cout << "White\n";
	

	return 0;
}
