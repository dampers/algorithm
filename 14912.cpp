#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	lld cnt = 0;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		int ttmp = i;
		while(ttmp)
		{
			int tmp = ttmp%10;
			if(tmp==m) cnt++;
			ttmp /= 10;
		}
	}
	printf("%lld", cnt);
	return 0;
}