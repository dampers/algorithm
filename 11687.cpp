#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

lld count_5(lld mid)
{
	lld tmp = mid/5, cnt = tmp;
	while(tmp>=5)
	{
		tmp /= 5;
		cnt += tmp;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lld m;
	cin>>m;

	lld l = 5, r = 5e9+1;
	while(l<r)
	{
		lld mid = (l+r)/2, cnt = count_5(mid);
		if(cnt<m) l = mid+1;
		else r = mid;
	}

	if(m==count_5(r)) cout<<r;
	else cout<<-1;

	return 0;
}