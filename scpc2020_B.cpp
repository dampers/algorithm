#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int x[3005], y[3005];
int sumx[3005], sumy[3005];
int indx[3005], indy[3005];
int mp[3003][3003];
int adx[] = {1, 0};
int ady[] = {0, 1};

int main()
{
	setbuf(stdout, NULL);
	time_t start, end;
	start = clock();
	int tc;
	scanf("%d", &tc);

	for(int t=1;t<=tc;t++)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &y[i]);
			sumy[i] = sumy[i-1]+y[i];
			indy[i] = -1;

		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &x[i]);
			sumx[i] = sumx[i-1]+x[i];
			indx[i] = -1;
		}
		memset(mp, 0, sizeof(mp));
		int mw = 2, ml = 2;

		mp[0][0] = mp[1][1] = 1;
		mp[1][0] = mp[0][1] = -1;

		indx[0] = indy[0] = 1;
		indx[1] = indy[1] = 0;

		queue<pair<int, int>> q;
		q.push({1, 0});
		q.push({0, 1});
		while(!q.empty())
		{
			int a = q.front().first, b = q.front().second;
			q.pop();
			for(int i=0;i<2;i++)
			{
				int na = a+ady[i], nb = b+adx[i];
				if(na>n || nb>n || mp[na][nb]) continue;
				if(indy[nb]>-1)
				{
					int sum = sumy[na]-sumy[indy[nb]];
					if(sum<=k)
					{
						mp[na][nb] = 1;
						mw++;
						q.push({na, nb});
						continue;
					}
				}
				if(indx[na]>-1)
				{
					int sum = sumx[nb]-sumx[indx[na]];
					if(sum<=k)
					{
						mp[na][nb] = 1;
						mw++;
						q.push({na, nb});
						continue;
					}
				}
				mp[na][nb] = -1;
				ml++;
				indy[nb] = max(na, indy[nb]);
				indx[na] = max(nb, indx[na]);
				q.push({na, nb});
			}
		}
		//printf("Case #%d\n%d %d\n", t, mw, ml);
	}
	end = clock();
	cout<<(double)(end-start)/1000;
	return 0;
}