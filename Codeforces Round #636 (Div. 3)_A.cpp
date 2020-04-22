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
		lld n;
		cin>>n;
		lld s = 3LL, t = 4LL;
		while(1)
		{
			if(n%s==0)
			{
				cout<<n/s<<endl;
				break;
			}
			s += t;
			t *= 2LL;
		}
	}
	return 0;
}