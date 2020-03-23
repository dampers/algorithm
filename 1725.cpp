#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld hs[100005];

lld solve(int s, int e)
{
	if(s==e) return hs[s];
	int mid = (s+e)/2;
	lld ans = max(solve(s, mid), solve(mid+1, e));
	int l = mid, r = mid, w = 1;
	lld h = hs[mid], mx = w*h;
	while(l<=r && l>=s && e>=r)
	{
		lld lmn = min(h, hs[l-1]);
		lld rmn = min(h, hs[r+1]);
		w++;
		if(w*lmn>w*rmn)
		{
			mx = max(mx, w*lmn);
			h = lmn;
			l--;
		}
		else
		{
			mx = max(mx, w*rmn);
			h = rmn;
			r++;
		}
	}
	ans = max(ans, mx);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(n==0) return 0;
	for(int i=1;i<=n;i++) cin>>hs[i];
	cout<<solve(1, n);
	return 0;
}