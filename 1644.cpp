#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

bool prime[4000005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	prime[0] = prime[1] = true;
	vector<lld> v;
	for(int i=2;i*i<=4000000;i++)
	{
		if(prime[i]) continue;
		for(int j=i+i;j<=4000000;j+=i)
			prime[j] = true;
	}

	v. push_back(0);
	for(int i=2;i<=4000000;i++)
		if(!prime[i]) v.push_back(*(v.end()-1)+i);
	
	lld n;
	cin>>n;

	int l = 0, r = 0, cnt = 0;
	while(l<=r && r<(int)v.size())
	{
		lld tmp = v[r]-v[l];
		if(tmp == n)
		{
			cnt++;
			l++;
			r++;
		}
		else if(tmp>n) l++;
		else r++;
	}
	cout<<cnt;
	return 0;
}