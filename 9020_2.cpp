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
	int n;
	cin>>n;
	while(n--)
	{
		int k, cnt = 0;
		cin>>k;
		for(int i=k/2;i>=2;i--)
			if((!prime[i]) && (!prime[k-i]))
			{
				cout<<i<<' '<<k-i<<endl;
				break;
			}
	}
	return 0;
}