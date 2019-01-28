#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int k = 1, cnt = 1;
		while(1)
		{
			if(k%n == 0)
			{
				printf("%d\n", cnt);
				break;
			}
			else k = (k%n)*10+1;
			cnt++;
		}
	}
	return 0;
}
