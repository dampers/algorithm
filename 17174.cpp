#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt = n, tmp = n/m, mm = n/m;
	while(tmp>m)
	{
		//cnt+=tmp;
		tmp /= m;
		mm += tmp;
	}
	printf("%d", cnt+mm);
	return 0;
}