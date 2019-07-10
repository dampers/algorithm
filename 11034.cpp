#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int d[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c;
	while(scanf(" %d %d %d", &a, &b, &c)==3)
	{
		d[0] = a;
		d[1] = b;
		d[2] = c;
		sort(d, d+3);
		int cnt = 0;
		while(d[1]-d[0]!=1 || d[2]-d[1]!=1)
		{
			cnt++;
			if(d[1]-d[0]>d[2]-d[1])
				d[2] = d[1]-1;
			else
				d[0] = d[1]+1;
			sort(d, d+3);
		}
		printf("%d\n", cnt);
	}
	return 0;
}