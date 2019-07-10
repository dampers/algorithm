#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0;
	while(scanf(" %d", &n)==1)
	{
		if(n>0)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}