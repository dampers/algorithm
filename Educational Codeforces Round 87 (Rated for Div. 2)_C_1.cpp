#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
 
#define PI 3.1415926535
 
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		double n;
		scanf("%lf", &n);
		n *= 2*(1.0);
		double r = 1/(2*tan(PI/n));
		printf("%.7lf\n", 2*r);
	}
	return 0;
}