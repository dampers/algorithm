#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int per[21];
int main()
{
	int t;
	scanf(" %d", &t);
	for(int i=0;i<t;i++)
	{
		int n, m, tmp = 0, mx = 0;
		scanf(" %d %d", &n, &m);
		for(int j=1;j<=n;j++)
		{
			for(int q=0;q<m;q++)
			{
				scanf(" %d", &tmp);
				if(tmp==1)
					per[j]++;
			}
			if(mx<per[j])
				mx = per[j];
		}
		int cnt = 0;
		for(int j=1;j<=n;j++)
		{
			if(per[j]==mx)
				cnt++;
		}
		printf("#%d %d %d\n", i+1, cnt, mx);
		for(int j=1;j<=n;j++)
			per[j] = 0;
	}
	return 0;
}