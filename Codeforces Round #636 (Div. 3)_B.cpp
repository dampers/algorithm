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
		if(n==2 || (n/2)%2==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		lld t = 0LL;
		for(int i=2;i<=n;i+=2)
		{
			cout<<i<<' ';
			t += (lld)i;
		}
		for(int i=1;i<n-1;i+=2)
		{
			cout<<i<<' ';
			t -= (lld)i;
		}
		cout<<t<<endl;
	}
	return 0;
}