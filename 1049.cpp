#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	scanf(" %d %d", &n, &m);
	int mn;
	int ma = 999999999;
	int mb = 999999999;
	for(int i=0;i<m;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		ma = min(ma, a);
		mb = min(mb, b);
	}
	int k = 0;
	if(n%6) k = 1;
	if(n<6)
		mn = min(ma, mb*n);
	else if(ma>mb*6)
		mn = mb*n;
	else
		mn = min((n/6)*ma+(n%6)*mb, (n/6+k)*ma);
	printf("%d", mn);
	return 0;
}