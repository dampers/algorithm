#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld c, k;
	scanf("%lld %lld", &c, &k);
	k = pow(10, k);
	lld a, b;
	a = c/k;
	b = c%k;
	a *= k;
	if(b>=k/2)
		a += k;
	printf("%lld", a);
	return 0;
}