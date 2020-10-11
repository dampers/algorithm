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
	for(int i=0;i<n;i++)
	{
		lld x, y;
		cin>>x>>y;
		yv[i] = y;
		xv[i] = x;
	}
	lld tx, ty;
	cin>>tx>>ty;
	bool right, left, down, up;
	right = left = down = up = false;
	for(int i=0;i<n;i++)
	{	
		if(abs(ty-yv[i])<=xv[i]-tx && xv[i]>=tx) right = true;
		if(abs(ty-yv[i])<=tx-xv[i] && tx>=xv[i]) left = true;
		if(abs(tx-xv[i])<=yv[i]-ty && yv[i]>=ty) down = true;
		if(abs(tx-xv[i])<=ty-yv[i] && ty>=yv[i]) up = true;
	}
	if(right && left && down && up) cout<<"NO";
	else cout<<"YES";

	return 0;
}