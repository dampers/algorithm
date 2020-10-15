#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld y, x;
	cin>>x>>y;
	lld z = (100*y)/x;
	lld l = 0, r = (lld)1e10, mid = (l+r)/2;
	while(l<=r)
	{
		mid = (l+r)/2;
		lld tmp = ((y+mid)*100)/(x+mid);
		if(tmp!=z) r = mid-1;
		else l = mid+1;
	}
	if(((y+l)*100)/(x+l) == z) cout<<-1;
	else cout<<l;

	return 0;
}