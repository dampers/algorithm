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
	
	int n, k;
	cin>>n>>k;
	int l = 1, r = 1000000000;
	int ans = 0;
	k--;
	while(l<=r)
	{
		int mid = (l+r)/2;
		lld sum = 0LL;
		for(int i=1;i<=n;i++)
		{
			sum += (mid/i)>n?n:(mid/i);
		}
		if(sum>k) r = mid-1;
		else if(sum<=k) l = mid+1;
	}
	cout<<l;

	return 0;
}