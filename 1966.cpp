#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int pq[10][101];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d", &tmp);
			pq[tmp][i]++;
		}
		int cnt = 0;
		bool flag = false;
		int id = 0;
		int qcnt = 0;
			if(flag) break;
			for(int i=9;i>0;i--)
			{
				qcnt = 0;
				for(int j=id;qcnt<n;j++)
				{
					qcnt++;
					if(j==n)
					{
						j = -1;
						continue;
					}
					if(pq[i][j]>0)
					{
						pq[i][j]--;
						cnt++;
						//printf("pq[%d][%d] = %d qcnt = %d m = %d cnt = %d\n", i, j,pq[i][j], qcnt, m, cnt);
						if(j==m)
						{
							flag = true;
							break;
						}
						id = j+1;
					}

				}
				if(flag) break;
			}
		printf("%d\n", cnt);
		for(int i=0;i<10;i++)
			for(int j=0;j<n;j++)
				pq[i][j] = 0;

	}
	return 0;
}
