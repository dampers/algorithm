#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char math[6][6];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf(" %c", &math[i][j]);
	queue <pair <int, pair<int, int> > > q;
	q.push({0,{0,(int)(math[0][0]-'0')}});
	int cnt = 0;
	bool flag = false;
	int mx = -999999, mn = 999999, size;
	while(!q.empty())
	{
		size = q.size();
		while(size--)
		{
			int x = q.front().second.first;
			int y = q.front().first;
			int k = q.front().second.second;
			//printf("%d %d %d\n", x, y, k);
			if(x==n-1 && y==n-1)
			{
				mx = max(mx, k);
				mn = min(mn, k);
			}
			char b = math[y][x];
			if(b>='0' && b<='5')
			{
				int dx = q.front().second.first+1;
				int dy = q.front().first;
				if(dx>=0 && dx<n && dy>=0 && dy<n)
					q.push(make_pair(dy,make_pair(dx,k)));
				dx = q.front().second.first;
				dy = q.front().first+1;
				if(dx>=0 && dx<n && dy>=0 && dy<n)
					q.push(make_pair(dy,make_pair(dx,k)));
			}
			else
			{
				int dx = q.front().second.first+1;
				int dy = q.front().first;
				k = q.front().second.second;
				if(dx>=0 && dx<n && dy>=0 && dy<n)
				{
					if(b=='+') k += (int)(math[dy][dx]-'0');
					else if(b=='-') k -= (int)(math[dy][dx]-'0');
					else if(b=='*') k *= (int)(math[dy][dx]-'0');
					q.push(make_pair(dy,make_pair(dx,k)));
				}
				dx = q.front().second.first;
				dy = q.front().first+1;
				k = q.front().second.second;
				if(dx>=0 && dx<n && dy>=0 && dy<n)
				{
					if(b=='+') k += (int)(math[dy][dx]-'0');
					else if(b=='-') k -= (int)(math[dy][dx]-'0');
					else if(b=='*') k *= (int)(math[dy][dx]-'0');
					q.push(make_pair(dy,make_pair(dx,k)));
				}
			}
			q.pop();
		}
	}
	printf("%d %d", mx, mn);
	return 0;
}