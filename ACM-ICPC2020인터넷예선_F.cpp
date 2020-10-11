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
	int n;
	cin>>n;
	vector<lld> yv(n), xv(n);
	lld mxy = (lld)(-1e9-1), mxx = (lld)(-1e9-1);
	lld mny = (lld)1e9+1, mnx = (lld)1e9+1;
	for(int i=0;i<n;i++)
	{
		lld x, y;
		cin>>x>>y;
		yv[i] = y;
		xv[i] = x;
		mxy = max(y, mxy);
		mxx = max(x, mxx);
		mny = min(y, mny);
		mnx = min(x, mnx);
	}
	lld tx, ty;
	cin>>tx>>ty;
	if(ty>mxy || ty<mny || tx>mxx || tx<mnx)
	{
		cout<<"NO";
		return 0;
	}
	bool right, left, down, up;
	right = left = down = up = false;
	for(int i=0;i<n;i++)
	{	
		//right
		if(abs(ty-yv[i])<=xv[i]-tx && xv[i]>=tx) right = true;
		//left
		if(abs(ty-yv[i])<=tx-xv[i] && tx>=xv[i]) left = true;
		//down
		if(abs(tx-xv[i])<=yv[i]-ty && yv[i]>=ty) down = true;
		// up
		if(abs(tx-xv[i])<=ty-yv[i] && ty>=yv[i]) up = true;
	}
	if(right && left && down && up) cout<<"NO";
	else cout<<"YES";

	return 0;
}