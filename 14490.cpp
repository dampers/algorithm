#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	char a;
	scanf("%d%c%d", &n, &a, &m);
	for(int i=2;i<=n;i++)
		{
			if(n%i==0 && m%i==0)
			{
				n = n/i;
				m = m/i;
				i = 2;
			}
		}
	printf("%d%c%d", n, a, m);
	return 0;
}
