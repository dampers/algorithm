#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
bool prime[1000005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[1] = true;
	for(int i=2;i*i<=1000000;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<=1000000;j+=i)
			prime[j] = true;
	}
	prime[2] = true;
	int n;
	while(1)
	{
		cin>>n;
		if(!n) break;
		bool flag = false;
		for(int i=3;i<=n/2;i++)
		{
			if(!prime[i] && !prime[n-i])
			{
				cout<<n<<" = "<<i<<" + "<<n-i<<endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout<<"Goldbach's conjecture is wrong."<<endl;
	}
	return 0;
}