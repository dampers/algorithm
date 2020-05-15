#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int a[33], b[33];

bool comp(int a, int b)
{
	return a>b;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, k;
		cin>>n>>k;
		int asum = 0, bsum = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			asum += a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			bsum += b[i];
		}
		sort(a, a+n);
		sort(b, b+n, comp);
		int ak = 0, bk = 0;
		while(k>0 && bk<n && ak<n)
		{
			if(a[ak]>b[bk])
			{
				bk++;
				continue;
			}
			asum -= a[ak++];
			asum += b[bk++];
			k--;
		}
		cout<<asum<<endl;

	}
	
	return 0;
}