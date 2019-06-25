#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	lld n, sum = 0;
	while(scanf("%lld", &n)==1)
		sum += n;
	printf("%lld", sum);
	return 0;
}