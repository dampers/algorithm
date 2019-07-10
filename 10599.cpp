#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, d;
	while(1)
	{
		cin>>a>>b>>c>>d;
		if(!a && !b && !c && !d)
			return 0;
		cout<<abs(b-c)<<' '<<abs(a-d)<<'\n';
	}

	return 0;
}