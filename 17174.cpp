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
	cin>>n>>m;
	int cnt = 0;
	while(n)
	{
		cnt += n;
		n /= m;
	}
	printf("%d", cnt);
	return 0;
}