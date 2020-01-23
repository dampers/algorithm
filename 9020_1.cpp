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
	for(int i=2;i<10000;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<10000;j+=i)
			prime[j] = true;
	}
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		for(int i=n/2;i>=0;i--)
		{
			if(!prime[i] && !prime[n-i])
			{
				cout<<i<<' '<<n-i<<endl;
				break;
			}
		}
	}
	return 0;
}