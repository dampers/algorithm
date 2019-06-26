#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld price[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int z=0;z<q;z++)
	{
		int n;
		lld k, mx;
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>price[i];
		sort(price, price+n);
		if(price[0]+k<price[n-1]-k)
	   	{
	        cout<<-1<<'\n';
	        continue;
	    }
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(price[i]-k>price[j]+k &&price[i]>price[j])
					continue;
				else if(price[i]+k<price[j]-k && price[i]<price[j])
					continue;
				if(j==n-1)
				{
					mx = price[0]+k;
				}
			}
		}
		cout<<mx<<"\n";
	}
	return 0;
	}