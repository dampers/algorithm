#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};

bool knight(int x, int y, int nx, int ny)
{
	for(int d=0;d<8;d++)
	{
		int xx = x+dx[d], yy = y+dy[d];
		if(xx == nx && yy == ny) return true;
	}
	return false;
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> v(6, vector<int>(6, 0));
	vector<string> vs(36);
	for(int i=0;i<36;i++)
	{
		cin >> vs[i];
	}
	int x = vs[0][0]-'A', y = 6-(vs[0][1]-'1')-1;
	bool flag = true;
	v[y][x] = 1;
	for(int i=1;i<36;i++)
	{
		int nx = vs[i][0]-'A', ny = 6-(vs[i][1]-'1')-1;
		if(knight(x, y, nx, ny) && v[ny][nx] == 0)
		{
			v[ny][nx] = 1;
			x = nx;
			y = ny;
		}
		else flag = false;
	}
	if(knight(x, y, vs[0][0]-'A', 6-(vs[0][1]-'1')-1) && flag) cout << "Valid";
	else cout << "Invalid";


	return 0;
}
