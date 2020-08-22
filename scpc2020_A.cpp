#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int a[200005], b[200005];

bool comp(int p, int q)
{
	return p>q;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		int n, k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a, a+n);
		sort(b, b+n, comp);
		int mx = 0;
		for(int i=0;i<k;i++)
		{
			mx = max(a[i]+b[n-k+i], mx);
		}

		cout<<"Case #"<<t<<endl;
		cout<<mx<<endl;

	}

	return 0;
}