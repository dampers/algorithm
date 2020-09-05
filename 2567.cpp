#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

bool paper[102][102];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int l, h;
		scanf(" %d %d", &l, &h);
		for(int j=l;j<l+10;j++)
		{
			for(int k=h;k<h+10;k++)
			{
				paper[j][k] = true;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			bool flag = false;
			int cnt = 0;
			if(paper[i][j])
			{
				for(int k=0;k<4;k++)
				{
					int ny = i+dy[k], nx = j+dx[k];
					if(ny>100 || nx>100 || ny<0 || ny<0 || paper[ny][nx]==false)
					{
						flag = true;
					}
					else if(paper[ny][nx]) cnt++;
				}
			}
			if(flag)
			{
				if(cnt==2) sum++;
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}