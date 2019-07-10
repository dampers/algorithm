#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		if(a%i==0 && b%i==0)
			cout<<i<<' '<<a/i<<' '<<b/i<<'\n';
	}
	return 0;
}