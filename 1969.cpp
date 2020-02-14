#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int gact[4][55];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char tmp;
			scanf(" %c", &tmp);
			if(tmp=='A') gact[0][j]++;
			else if(tmp=='C') gact[1][j]++;
			else if(tmp=='G') gact[2][j]++;
			else gact[3][j]++;
		}
	}
	int cnt = 0;
	for(int i=0;i<m;i++)
	{
		int ind = 0;
		for(int j=1;j<4;j++)
		{
			if(gact[j][i]>gact[ind][i]) ind = j;
		}
		if(ind==0) printf("A");
		else if(ind==1) printf("C");
		else if(ind==2) printf("G");
		else printf("T");
		cnt += n-gact[ind][i];
	}
	printf("\n%d", cnt);
	return 0;
}