#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

bool prime[10005];
char vol[6] = {'a', 'e', 'i', 'o', 'u', '\0'};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin>>k;
	prime[1] = prime[0] = true;
	for(int i=2;i<=10000;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<=10000;j+=i)
			prime[j] = true;
	}
	if(!prime[k] || k<25)
	{
		cout<<-1;
		return 0;
	}
	for(int i=5;i<=k;i++)
	{
		if(k%i==0)
		{
			int tmp = k/i;
			if(tmp>=5)
			{
				for(int r=0;r<i;r++)
				{
					for(int l=0;l<tmp;l++)
					{
						cout<<vol[(r+l)%5];
					}
					//cout<<endl;
				}
				return 0;

			}
		}
	}
	cout<<-1;
	return 0;
}