#include <bits/stdc++.h>
#define swap(a,b) a^=b^=a^=b
using namespace std;
typedef long long lld;

queue<int> bfs;
bool visit[30][30];
char apt[30][30];
vector<int> as;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int main()
{
	int n, cnt = 0;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %c", &apt[i][j]);
		}
	}
	int x, y, nx, ny, acnt = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(apt[i][j]=='1' && !visit[i][j])
			{
				acnt = 0;
				cnt++;
				//printf("cnt = %d\n", cnt);
				visit[i][j] = true;
				bfs.push(i);
				bfs.push(j);
				while(!bfs.empty())
				{
					acnt++;
					int size = bfs.size();
					y = bfs.front();
					bfs.pop();
					x = bfs.front();
					bfs.pop();
					//printf("y = %d x = %d\n", y, x);
					while(size--)
					{
						for(int q=0;q<4;q++)
						{
							nx = x+dx[q];
							ny = y+dy[q];
							if(nx>=0&&nx<26&&ny>=0&&ny<26&&!visit[ny][nx]&&apt[ny][nx] =='1')
							{
								visit[ny][nx] = true;
								bfs.push(ny);
								bfs.push(nx);
							}
						}
					}
				}
				as.push_back(acnt);
			}
		}
	}
	printf("%d\n", cnt);
	sort(as.begin(),as.end());
	for (int i = 0; i < cnt; i++)
	{
		printf("%d\n", as[i]);
	}
	return 0;
}
