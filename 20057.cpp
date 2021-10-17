#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[4][9]  =  {{0, 0, 0, 0, 1, 1, -1, -1, -2},
						{-1, -2, 1, 2, 1, -1, 1, -1, 0},
						{0, 0, 0, 0, -1, -1, 1, 1, 2},
						{1, 2, -1, -2, -1, 1, -1, 1, 0}};
const int dy[4][9]  =  {{-1, -2, 1, 2, 1, -1, 1, -1, 0},
						{0, 0, 0, 0, -1, -1, 1, 1, 2},
						{1, 2, -1, -2, -1, 1, -1, 1, 0},
						{0, 0, 0, 0, 1, 1, -1, -1, -2}};
const int pers[9] = {7, 2, 7, 2, 1, 1, 10, 10, 5};

const int kdx[4] = {-1, 0, 1, 0};
const int kdy[4] = {0, 1, 0, -1};
int n;

void move(int &y, int &x, int dir, int kns, int move_size, int& ans, vector<vector<int>>& v)
{
	for(int kn=0;kn<kns;kn++)
	{
		for(int k=0;k<move_size;k++)
		{
			y += kdy[dir];
			x += kdx[dir];
			int tmpsum = 0;
			for(int i=0;i<9;i++)
			{
				int ny = y+dy[dir][i];
				int nx = x+dx[dir][i];
				int sands = (v[y][x] * pers[i])/100;
				tmpsum += sands;
				if(ny >= n || nx >= n || ny < 0 || nx < 0)
					ans += sands;
				else v[ny][nx] += sands;
			}
			int ky = y+kdy[dir], kx = x+kdx[dir];
			if(ky >= n || kx >= n || ky < 0 || kx < 0)
				ans += v[y][x]-tmpsum;
			else v[ky][kx] += (v[y][x]-tmpsum);
			v[y][x] = 0;
		}
		dir++;
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> v[i][j];

	int move_size = 1;
	int y = n/2, x = n/2;
	int ans = 0;
	while(move_size < n)
	{
		int dir = move_size%2?0:2;
		move(y, x, dir, 2, move_size, ans, v);
		move_size++;
	}
	move(y, x, 0, 1, n-1, ans, v);
	cout << ans;
	return 0;
}