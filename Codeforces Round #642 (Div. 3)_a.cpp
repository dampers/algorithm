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
		lld n, m;
		cin>>n>>m;
		if(n==1) cout<<0<<endl;
		else if(n==2) cout<<m<<endl;
		else cout<<m*2<<endl;
	}
	return 0;
}