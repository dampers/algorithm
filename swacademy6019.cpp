#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf("%d", &n);
	for(int tc=1;tc<=n;tc++)
	{
		double d, a, b ,f;
		scanf(" %lf %lf %lf %lf", &d, &a, &b, &f);
		printf("#%d %.6lf", tc, (d/(a+b))*f);
	}
	return 0;
}