#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	cin>>n;
	if(n==1)
	{
		printf("1/1");
		return 0;
	}
	for(int i=5000;i>=0;i--)
	{
		if(i*(i+1)/2<n)
		{
			n -= i*(i+1)/2;
			tmp = i+1;
			break;
		}
	}
	int h, r;
	if(tmp%2)
	{
		h = tmp-n+1;
		r = n;
	}
	else
	{
		h = n;
		r = tmp-n+1;
	}
	printf("%d/%d",h, r);
	return 0;
}