#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, tmp = 64, cnt = 0;
	cin>>x;
	while(tmp)
	{
		if(tmp<=x)
		{
			x-=tmp;
			cnt++;
		}
		if(x==0) break;
		tmp /= 2;
	}
	printf("%d", cnt);
	return 0;
}