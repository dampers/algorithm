#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=1;i<=n;i++)
	{
		int c = 0, tmp;
		for(int j=1;j<=10;j++)
		{
			scanf(" %d", &tmp);
			if((j-1)%5+1==tmp)
				c++;
		}
		if(c == 10) printf("%d\n", i);
	}
	return 0;
}