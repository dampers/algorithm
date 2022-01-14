#include <bits/stdc++.h>

using namespace std;

#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long

using pii = pair<int, int>;

const double EPS = 1e-9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};


int r, c;

class Shark
{
public:
	int speed, dir, z;
	Shark()
	{
		this->z = -1;
		this->dir = -1;
		this->speed = -1;
	}
	Shark(int speed, int dir, int z) : dir(dir), speed(speed), z(z) {}
	void set(int z, int dir, int speed)
	{
		this->z = z;
		this->dir = dir;
		this->speed = speed;
	}
	void set(Shark K)
	{
		this->z = K.z;
		this->dir = K.dir;
		this->speed = K.speed;
	}
	void reset()
	{
		this->z = -1;
		this->dir = -1;
		this->speed = -1;
	}
};

void printv(vector<vector<Shark>>& v)
{
	for(size_t i=0;i<v.size();i++)
	{
		for(size_t j=0;j<v[i].size();j++)
		{
			if(v[i][j].z == -1) cout << 0 << ' ';
			else cout << v[i][j].z << ' ';
		}
		cout << endl;
	}
}

void move(vector<vector<Shark>>& v, vector<vector<Shark>>& movev)
{
	for(size_t i=0;i<v.size();i++)
	{
		for(size_t j=0;j<v[i].size();j++)
		{
			if(v[i][j].z == -1) continue;
			int ty = i, tx = j, tdir = v[i][j].dir, tz = v[i][j].z, tspeed = v[i][j].speed;
			
			if(v[i][j].dir == 0 || v[i][j].dir == 1)
			{
				if(v[i][j].dir == 0) ty += (r-1-ty) * 2;
				ty = (ty + v[i][j].speed) % (r+r-2);
				tdir = 1;
				if(ty >= r)
				{
					ty = (ty-(r+r-2)) * -1;
					tdir = 0;
				}

			}
			if(v[i][j].dir == 2 || v[i][j].dir == 3)
			{
				if(v[i][j].dir == 3) tx += (c-1-tx) * 2;
				tx = (tx+v[i][j].speed) % (c+c-2);
				tdir = 2;
				if(tx >= c)
				{
					tx = (tx-(c+c-2)) * -1;
					tdir = 3;
				}
			}
			if(movev[ty][tx].z < tz)
			{
				movev[ty][tx].set(tz, tdir, tspeed);
			}
			v[i][j].reset();
		}
	}
	for(size_t i=0;i<movev.size();i++)
	{
		for(size_t j=0;j<movev[i].size();j++)
		{
			if(movev[i][j].z == -1) continue;
			v[i][j].set(movev[i][j]);
			movev[i][j].reset();
		}
	}
}

int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> r >> c >> m;
	vector<vector<Shark>> v(r, vector<Shark>(c, Shark())), movev(r, vector<Shark>(c, Shark()));
	int tr, tc, tspeed, tdir, tz;

	for(int i=0;i<m;i++)
	{
		cin >> tr >> tc >> tspeed >> tdir >> tz;
		tr--;
		tc--;
		tdir--;
		if(tr == 0 && tdir == 0) tdir = 1;
		if(tr == r-1 && tdir == 1) tdir = 0;
		if(tc == c-1 && tdir == 2) tdir = 3;
		if(tc == 0 && tdir == 3) tdir = 2;
		v[tr][tc].speed = tspeed;
		v[tr][tc].dir = tdir;
		v[tr][tc].z = tz;
	}


	int ans = 0;
	for(int fx=0;fx<c;fx++)
	{
		for(int fy=0;fy<r;fy++)
		{
			if(v[fy][fx].z != -1)
			{
				ans += v[fy][fx].z;
				v[fy][fx].reset();
				break;
			}
		}
		move(v, movev);
		//cout << ans << endl;
	}
	cout << ans;
	return 0;
}