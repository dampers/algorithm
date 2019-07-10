#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, d, k;
	scanf("%d %d %d", &a, &d, &k);
	int cnt = 1;
	while(1)
	{
		if(d>0)
		{
			if(a<k)
			{
				a += d;
				cnt++;
			}
			else if(a==k)
			{
				printf("%d", cnt);
				break;
			}
			else
			{
				printf("X");
				break;
			}
		}
		else
		{
			if(a>k)
			{
				a += d;
				cnt++;
			}
			else if(a==k)
			{
				printf("%d", cnt);
				break;
			}
			else
			{
				printf("X");
				break;
			}
		}
	}
	return 0;
}