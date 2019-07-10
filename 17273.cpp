#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int a, b, c;
	cin>>a>>b;
	c = a;
	for(int i=0;i<m;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp>=c)
		{
			if(c==a)
				c = b;
			else
				c = a;
		}
	}
	printf("%d", c);
	return 0;
}