#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	double n;
	scanf("%lf", &n);
	n /= 2;
	n *= n;
	if((int)n+0.5>n) n = (int)n+0.0;
	else n = (int)n+1.0;
	printf("%.0lf", n);
	return 0;
}