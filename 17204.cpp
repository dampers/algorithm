#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int game[151];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++)
		scanf(" %d", &game[i]);
	int cnt = 1, s = game[0];
	for(int i=0;i<2*n;i++)
	{
		if(s==k)
		{
			printf("%d", cnt);
			return 0;
		}
		cnt++;
		s = game[s];
	}
	printf("-1");
	return 0;
}