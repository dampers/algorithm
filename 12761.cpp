#include <bits/stdc++.h>
#define swap(a,b) a^=b^=a^=b
using namespace std;
typedef long long lld;
bool visit[100005];

queue<int> bfs;

int main()
{
	int a, b, n, m, cnt = 0, nx, ax;
	scanf("%d %d %d %d",&a, &b, &n, &m);
	bfs.push(n);
	visit[n] = true;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			nx = bfs.front();
			bfs.pop();
			if(nx==m)
				break;
			for(int i=0;i<8;i++)
			{
				switch(i)
				{
					case 0:
						ax = nx+1; break;
					case 1:
						ax = nx-1; break;
					case 2:
						ax = nx*a; break;
					case 3:
						ax = nx*b; break;
					case 4:
						ax = nx+a; break;
					case 5:
						ax = nx-a; break;
					case 6:
						ax = nx+b; break;
					case 7:
						ax = nx-b; break;
					default:
						break;
				}
				if(ax<0||ax>100000) continue;
				else if(visit[ax]) continue;
				bfs.push(ax);
				visit[ax] = true;
			}
		}
		if(nx==m)
			break;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}