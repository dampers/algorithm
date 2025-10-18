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

int N, K, L;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

void print_vs(vector<vector<int>>& v)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int simulate(vector<vector<int>>& v, vector<pair<int, string>>& vo)
{
    // 초기 위치는 (1, 1)
    // 길이 1
    // 방향 오른쪽
    int y = 1, x = 1;
    int slen = 1, dir = 0;
    int second = 0;
    bool dead = false;
    queue<pii> snake;
    snake.push({y, x});
    v[y][x] = 2;

    int vo_idx = 1;
    int target_second = vo[0].first;
    int next_dir = vo[0].second[0]=='D'?((dir+1) % 4):((dir+3) % 4);
    
    while(1)
    {
        second++;
        y = y+dy[dir];
        x = x+dx[dir];
        if(y > N || x > N || y <= 0 || x <=0) return second;
        if(v[y][x] == 2) return second;
        if(v[y][x] == 0)
        {
            pii tail = snake.front();
            v[tail.first][tail.second] = 0;
            snake.pop();
        }
        v[y][x] = 2;
        snake.push({y, x});
        // print_vs(v);
        if(second == target_second)
        {
            dir = next_dir;
            if(vo_idx < L)
            {
                target_second = vo[vo_idx].first;
                next_dir = vo[vo_idx].second[0]=='D'?((dir+1) % 4):((dir+3) % 4);
                vo_idx++;
            }
        }
    }
    return second;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N >> K;
    vector<vector<int>> v(N+1, vector<int>(N+1, 0));
    for(int i=0;i<K;i++)
    {
        int y, x;
        cin >> y >> x;
        v[y][x] = 1;
    }

    cin >> L;
    vector<pair<int, string>> vo(L);
    for(int i=0;i<L;i++)
    {
        cin >> vo[i].first >> vo[i].second;
    }
    cout << simulate(v, vo);
	
 	return 0;
}