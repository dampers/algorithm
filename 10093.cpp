#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	lld a, b;
	scanf("%lld %lld", &a, &b);
	lld tmp;
	if(a>b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(a==b) printf("0");
	else
	{
		printf("%lld\n", b-a-1);
		for(lld i=a+1;i<b;i++) printf("%lld ", i);
	}
	return 0;
}