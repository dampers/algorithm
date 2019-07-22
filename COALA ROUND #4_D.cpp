#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, m, a;
	scanf("%lld %lld %lld", &n, &m, &a);
	long long ncnt = n%a?1:0, mcnt = m%a?1:0;
	printf("%lld", (n/a+ncnt)*(m/a+mcnt));
	return 0;
}
