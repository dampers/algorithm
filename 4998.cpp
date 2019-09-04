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
	double n, m, b;
	while(scanf("%lf %lf %lf", &n, &b, &m)>2)
	{
		int cnt = 0;
		while(n<m)
		{
			n += n*(b/100);
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}