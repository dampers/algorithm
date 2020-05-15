#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		lld k = 0LL, cnt = 8LL;
		for(int i=1;i<=n/2;i++)
		{
			k += i*cnt;
			cnt += 8;
		}
		cout<<k<<endl;
	}
	
	return 0;
}