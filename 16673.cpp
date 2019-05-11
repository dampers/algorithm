#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	int n, k, p;
	lld sum = 0;
	scanf("%d %d %d", &n, &k, &p);
	for(int i=1;i<=n;i++)
	{
		sum += i*(k+p*i);
	}
	printf("%lld", sum);
	return 0;
}