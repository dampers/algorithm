# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, c = 1;
	scanf("%d %d", &n, &m);
	int k = m;
	for(int i=0;i<k;i++)
	{
		c = c*n;
		n--;
	}
	for(int i=0;i<k;i++)
	{
		c = c/m;
		m--;
	}
	printf("%d", c);
	return 0;
}
