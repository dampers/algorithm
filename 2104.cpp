#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[100005];

lld solve(int s, int e)
{
	if(s==e) return num[s]*num[s];
	int mid = (s+e)/2;
	lld ans = max(solve(s, mid), solve(mid+1, e));
	cout<<endl;
	int l = mid, r = mid;
	lld mn = num[l], sum = num[l], mx = mn*sum;
	cout<<mid<<endl;
	while(l<=r && l>=s && r<e)
	{
		lld rsum = sum+num[r+1], rmn = min(mn, num[r+1]);
		lld lsum = sum+num[l-1], lmn = min(mn, num[l-1]);
		cout<<l-1<<' '<<r+1<<endl;
		if(rsum*rmn > lsum*lmn)
		{
			r++;
			mx = max(rsum*rmn, mx);
			sum = rsum;
			mn = rmn;
		}
		else
		{
			l--;
			mx = max(lsum*lmn, mx);
			sum = lsum;
			mn = lmn;
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
	lld n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	cout<<solve(1, n);
	return 0;
}