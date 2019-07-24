#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;
int num[200004];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int tc=0;tc<q;tc++)
	{
		int n, k;
		cin>>n>>k;
		int od = 0;
		int g = k;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			if(num[i]%2)
				od++;
		}
		if(od/k==0)
		{
			cout<<"NO\n";
		}
		else if(k==1)
		{
			if(od%2)
			{
				cout<<"YES\n";
				cout<<n<<'\n';
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else if((od-(k-1))%2)
		{
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				if(num[i]%2)
				{
					cout<<i+1<<' ';
					g--;
				}
				if(g==1)
				{
					cout<<n<<'\n';
					break;
				}
			}
		}
		else
		{
			cout<<"NO\n";
			continue;
		}
	}
	return 0;
}