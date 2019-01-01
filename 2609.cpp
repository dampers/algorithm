# include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, a, b;
	int cnt = 1;
	scanf("%d %d", &a, &b);
	for(int j=1;j<=a;j++)
	{
			if(a%j==0 && b%j==0)		
		{
			cnt *= j;
			a = a/j;
			b = b/j;
			j = 1;
		}
	}
	printf("%d\n%d", cnt, a*b*cnt);
	return 0;
}
