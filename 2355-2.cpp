#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, tmp, sum = 0;
	scanf("%lld %lld", &a, &b);
	if(a>b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(a == b) sum = a;
	else
	{
		if(a<0) sum -= (a*(a-1))/2;
		else sum -= (a*(a-1))/2;
		if(b<0) sum += (b*(b+1))/2;
		else sum += (b*(b+1))/2;
	}
	printf("%lld", sum);
	return 0;
}
