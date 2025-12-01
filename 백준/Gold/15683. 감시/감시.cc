#include <bits/stdc++.h>

using namespace std;

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const double EPS = 1e-9;
const int dx1[4] = {1, -1, 0, 0};
const int dy1[4] = {0, 0, 1, -1};
const int dx2[2][2] = {{1, -1}, {0, 0}};
const int dy2[2][2] = {{0, 0}, {1, -1}};
const int dx3[4][2] = {{0, 1}, {0, 1}, {0, -1}, {0, -1}};
const int dy3[4][2] = {{-1, 0}, {1, 0}, {-1, 0}, {1, 0}};

int N, M;
int office[10][10];
int dir[10];
int cnt = 1e9;

void count_color(vector<pair<int, int>>& cctv)
{
    int ocpy[10][10];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            ocpy[i][j] = office[i][j];
    
    queue<pair<pair<int, pair<int, int>>, pair<int, int>>> q;
    for(size_t i=0;i<cctv.size();i++)
    {
        int y = cctv[i].first;
        int x = cctv[i].second;
        int tdir = dir[i];
        // cout << "number: " << ocpy[y][x] << ' ' << tdir << endl;
        if(ocpy[y][x] == 1)
            q.push({{ocpy[y][x], {dy1[tdir], dx1[tdir]}}, {y, x}});
        else if(ocpy[y][x] == 2)
        {
            q.push({{ocpy[y][x], {dy2[tdir][0], dx2[tdir][0]}}, {y, x}});
            q.push({{ocpy[y][x], {dy2[tdir][1], dx2[tdir][1]}}, {y, x}});
        }
        else if(ocpy[y][x] == 3)
        {
            q.push({{ocpy[y][x], {dy3[tdir][0], dx3[tdir][0]}}, {y, x}});
            q.push({{ocpy[y][x], {dy3[tdir][1], dx3[tdir][1]}}, {y, x}});
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                if(ocpy[y][x] == 4 && i == tdir) continue;
                q.push({{ocpy[y][x], {dy1[i], dx1[i]}}, {y, x}});
            }
        }
    }

    // cout << q.size() << endl;
    while(!q.empty())
    {
        
        int type = q.front().first.first;
        int dy = q.front().first.second.first;
        int dx = q.front().first.second.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        // cout << type << ' ' << y << ' ' << x << ' ' << dy << ' ' << dx << endl;
        // cout << y+dy << ' ' << x+dx << endl;

        int ny = y+dy;
        int nx = x+dx;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(ocpy[ny][nx] == 6) continue;
        if(ocpy[ny][nx] == 0) ocpy[ny][nx] = -1;
        q.push({{type, {dy, dx}}, {ny, nx}});
        
    }

    int ccnt = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(ocpy[i][j] == 0) ccnt++;
        }
    }
    cnt = min(ccnt, cnt);

}

void recurr(int pos, vector<pair<int, int>>& cctv)
{
    if(pos == cctv.size())
    {
        count_color(cctv);
        return;
    }
    int y = cctv[pos].first;
    int x = cctv[pos].second;

    int dircnt = 0;
    if(office[y][x] == 5) dircnt = 1;
    else if(office[y][x] == 2) dircnt = 2;
    else dircnt = 4;
    
    for(int i=0;i<dircnt;i++)
    {
        dir[pos] = i;
        recurr(pos+1, cctv);
    }
}

int32_t main()
{
    cin.sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    vector<pair<int, int>> cctv;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> office[i][j];
            if(office[i][j] > 0 && office[i][j] < 6) cctv.push_back({i, j});
        }
    }
    recurr(0, cctv);
    cout << cnt;


    return 0;
}