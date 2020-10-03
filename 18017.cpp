#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

#define C 299792458.0

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.12lf", (a+b)/(1+(a*b)/(C*C)));
	return 0;
}