#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

class miro
{
public:
	int y;
	int x;
	bool keys[7];
	miro(int yy, int xx)
	{
		y = yy;
		x = xx;
		for(int i=0;i<6;i++)
			keys[i] = false;
	}
};

char moon[55][55];
bool check[65][55][55];
bool tmpkey[7];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	queue<miro> bfs;
	vector <pair<int, int> > out;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %c", &moon[i][j]);
			if(moon[i][j]=='0')
			{
				miro mtmp(i, j);
				bfs.push(mtmp);
				check[0][i][j] = true;
			}
			else if(moon[i][j]=='1')
			{
				out.push_back({i, j});
			}
		}
	}
	int outsize = out.size();
	int cnt = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int y = bfs.front().y, x = bfs.front().x, k = 0;
			for(int i=0;i<6;i++)
			{
				tmpkey[i] = bfs.front().keys[i];
				if(tmpkey[i]) k += pow(2, i);
			}
			bfs.pop();
			//printf("\ny = %d x = %d k = %d\n", y, x ,k);
			for(int i=0;i<4;i++)
			{
				int ny = y+dy[i], nx = x+dx[i], nk = k;
				if(ny>=n||ny<0||nx>=m||nx<0||check[nk][ny][nx]||moon[ny][nx]=='#') continue;
				for(int j=0;j<outsize;j++)
				{
					if(ny==out[j].first && nx==out[j].second)
					{
						printf("%d", cnt+1);
						return 0;
					}
				}
				miro tmp(ny, nx);
				for(int j=0;j<6;j++)
					tmp.keys[j] = tmpkey[j];
				if(moon[ny][nx]>='a' && moon[ny][nx]<='f')
				{
					int ktmp = (int)(moon[ny][nx]-'a');
					if(!tmpkey[ktmp])
					{
						tmp.keys[ktmp] = true;
						nk += pow(2, ktmp);
					}
					bfs.push(tmp);
					check[nk][ny][nx] = true;
				}
				else if(moon[ny][nx]>='A'&&moon[ny][nx]<='F')
				{
					int ktmp = (int)(moon[ny][nx]-'A');
					if(tmpkey[ktmp])
					{
						bfs.push(tmp);
						check[nk][ny][nx] = true;
					}
				}
				else if(moon[ny][nx]=='.' || moon[ny][nx]=='0')
				{
					bfs.push(tmp);
					check[nk][ny][nx] = true;
				}
				//printf("ny = %d nx = %d nk = %d\n", ny, nx, nk);
			}
		}
		cnt++;
	}
	printf("-1");
	return 0;
}