#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
bool prime[1005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	prime[1] = true;
	for(int i=2;i*i<1001;i++)
	{
		if(prime[i]==true) continue;
		for(int j=i+i;j<1001;j+=i)
			prime[j] = true;
	}
	vector<int> p;
	for(int i=2;i<1001;i++)
		if(prime[i]==false)
			p.push_back(i);
	int n, k;
	cin>>n>>k;
	int size = p.size();
	for(int i=0;i<size-1;i++)
	{
		int tmp = p[i]+p[i+1]+1;
		if(tmp<=n && !prime[tmp])
			k--;
		if(k==0)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}