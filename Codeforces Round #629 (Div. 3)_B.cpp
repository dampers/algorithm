#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool ab[100005];
lld sum[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(lld i=1;i<100001;i++)
	{
		sum[i] = sum[i-1]+i;
	}
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		lld k;
		cin>>n>>k;
		memset(ab, false, sizeof(ab));
		int l = 0, r = n, mid = (l+r)/2, ks;
		while(l<=r)
		{
			mid = (l+r)/2;
			if(k-sum[mid]<0) r = mid-1;
			else if(k-sum[mid]>0) l = mid+1;
			else
			{
				ks = mid;
				break;
			}
		}
		ks = mid;
		if(k-sum[ks]<0) ks--;
		else if(k-sum[ks]==0)
		{
			ab[n-1-ks] = ab[n-ks] = true;
			for(int i=0;i<n;i++)
			{
				if(ab[i]) cout<<'b';
				else cout<<'a';
			}
			cout<<endl;
			continue;
		}
		ab[n-2-ks] = true;
		ab[n-k+sum[ks]] = true;
		for(int i=0;i<n;i++)
		{
			if(ab[i]) cout<<'b';
			else cout<<'a';
		}
		cout<<endl;
	}
	return 0;
}