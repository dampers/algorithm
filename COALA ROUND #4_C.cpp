#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	scanf("%d", &a);
	int cnt = 0;
	for(int i=2;i<a;i++)
	{
		int tmp = 0, aa = a;
		while(aa)
		{
			tmp += aa%i;
			aa /= i;
		}
		cnt += tmp;
	}
	int d = a-2;
	int k = 1;
	for(int i=2;i<=cnt;i++)
	{
		if(cnt%i==0 && d%i==0) k = i;
	}
	printf("%d/%d", cnt/k, d/k);
	return 0;
}
