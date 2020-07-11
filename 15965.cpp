#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool prime[10000005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[0] = prime[1] = true;
	for(int i=2;i<10000005;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<10000005;j+=i)
			prime[j] = true;
	}
	int k;
	cin>>k;
	for(int i=2;i<10000005;i++)
	{
		if(!prime[i]) k--;
		if(k==0)
		{
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}
