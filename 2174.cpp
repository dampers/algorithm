#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

struct robot
{
	int x;
	int y;
	char dir;
};

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b;
	cin>>a>>b;
	vector<vector<int>> mp(b, vector<int>(a, 0));
	int n, m;
	cin>>n>>m;
	vector<robot> r(n);
	char tmp;
	map<char, int> direction;
	direction['E'] = 0;
	direction['N'] = 1;
	direction['W'] = 2;
	direction['S'] = 3;
	map<int, char> dirs;
	dirs[0] = 'E';
	dirs[1] = 'N';
	dirs[2] = 'W';
	dirs[3] = 'S';
	for(int i=0;i<n;i++)
	{
		cin>>r[i].x>>r[i].y>>r[i].dir;
		r[i].x--;
		r[i].y = b-r[i].y;
		mp[r[i].y][r[i].x] = i+1;
	}
	for(int i=0;i<m;i++)
	{
		int num, loop;
		char command;
		cin>>num>>command>>loop;
		int dirnum = direction[r[num-1].dir];
		mp[r[num-1].y][r[num-1].x] = 0;
		for(int j=0;j<loop;j++)
		{
			if(command=='F')
			{
				int ny = r[num-1].y+dy[dirnum], nx = r[num-1].x+dx[dirnum];
				if(ny>=b || nx>=a ||ny<0 || nx<0)
				{
					cout<<"Robot "<<num<<" crashes into the wall";
					return 0;
				}
				else if(mp[ny][nx]!=0)
				{
					cout<<"Robot "<<num<<" crashes into robot "<<mp[ny][nx];
					return 0;
				}
				r[num-1].y = ny;
				r[num-1].x = nx;
			}
			else if(command=='L') dirnum = (dirnum+1)%4;
			else if(command=='R') dirnum = dirnum?dirnum-1:3;
		}
		if(command=='F') mp[r[num-1].y][r[num-1].x] = num;
		else r[num-1].dir = dirs[dirnum];
	}
	cout<<"OK";
	return 0;
}