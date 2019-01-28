#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int main()
{
	int t;
	scanf(" %d", &t);
	if(t%10) printf("-1");
	else
	{
		int a = 0, b = 0, c = 0;
		while(t)
		{
			if(t>=300)
			{
				t -= 300;
				a++;
				continue;
			}
			else if(t>=60)
			{
				t -= 60;
				b++;
				continue;
			}
			else if(t>=10)
			{
				t -= 10;
				c++;
				continue;
			}
		}
		printf("%d %d %d", a, b, c);
	}
	
	return 0;
}