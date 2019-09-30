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
	int a, b, n, w;
	bool flag = false;
	cin>>a>>b>>n>>w;
	int q = 0, e = 0;
	for(int i=1;i<n;i++)
	{
		if(a*i+b*(n-i)==w)
		{
			if(flag)
			{
				printf("-1");
				return 0;
			}
			q = i;
			e = n-i;
			flag = true;
		}
	}
	if(flag) printf("%d %d", q, e);
	else printf("-1");
	return 0;
}