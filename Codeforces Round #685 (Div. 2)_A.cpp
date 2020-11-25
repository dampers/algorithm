#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
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
		else if(n==2)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n%2==0 || n==3)
		{
			cout<<2<<endl;
			continue;
		}
		else cout<<3<<endl;
	}
	return 0;
}