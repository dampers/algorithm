#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int ha[101][101], hb[101][101];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %d", &ha[i][j]);
	int k;
	scanf("%d %d", &m, &k);
	for(int i=0;i<m;i++)
		for(int j=0;j<k;j++)
			scanf(" %d", &hb[i][j]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int tmp = 0;
			for(int q=0;q<m;q++)
			{
				tmp += ha[i][q]*hb[q][j];
			}
			printf("%d ", tmp);
		}
		printf("\n");
	}
	return 0;
}