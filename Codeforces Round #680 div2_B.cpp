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
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		if(a+b>=c+d)
		{
			cout<<a+b<<endl;
		}
		else cout<<c+d<<endl;


	}
	return 0;
}