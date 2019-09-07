#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool prime[10005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[1] = true;
	for(int i=2;i*i<=10000;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<=10000;j+=i)
			prime[j] = true;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool flag = false;
		int l = n/2, r = n/2;
		for(int i=0;i<n;i++)
		{
			if(prime[l] || prime[r])
			{
				l--;
				r++;
			}
			else if(l+r==n)
			{
				cout<<l<<' '<<r<<endl;
				break;
			}
			else if(l+r>n) r++;
			else l--;
		}
	}
	return 0;
}