#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n, m;
bool cmp(vector<vector<int>>& mp, vector<vector<int>>& tmp, int r, int c)
{
	for(int i=0;i<=n-r;i++)
	{
		for(int j=0;j<=m-c;j++)
		{
			bool flag = true;
			for(int sy=i;sy<i+r;sy++)
			{
				for(int sx=j;sx<j+c;sx++)
				{
					if(tmp[sy-i][sx-j]==1 && mp[sy][sx]==1)
					{
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag)
			{
				for(int sy=i;sy<i+r;sy++)
					for(int sx=j;sx<j+c;sx++)
						if(tmp[sy-i][sx-j]==1) mp[sy][sx] = 1;
				return flag;
			}
			
		}
	}
	return false;
}

void rotate(vector<vector<int>>& tmp, vector<vector<int>>& rtmp)
{
	int r = (int)tmp.size(), c = (int)tmp[0].size();
	for(int i=0;i<c;i++)
		for(int j=0;j<r;j++)
			rtmp[i][j] = tmp[r-j-1][i];
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin>>n>>m>>k;
	vector<vector<int>> mp(n, vector<int>(m, 0));
	int total = n*m;
	for(int kc=0;kc<k;kc++)
	{
		int r, c, one = 0;
		cin>>r>>c;
		vector<vector<int>> tmp(r, vector<int>(c, 0));
		vector<vector<int>> rtmp(c, vector<int>(r, 0));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>tmp[i][j];
				if(tmp[i][j]==1) one++;
			}
		}

		if(total<one) continue;
		
		for(int i=0;i<4;i++)
		{
			if(i%2)
			{
				if(cmp(mp, rtmp, c, r))
				{
					total -= one;
					break;
				}
				else rotate(rtmp, tmp);
			}
			else
			{
				if(cmp(mp, tmp, r, c))
				{
					total -= one;
					break;
				}
				else rotate(tmp, rtmp);
			}
		}
		
	}
	cout<<n*m-total;
	return 0;
}