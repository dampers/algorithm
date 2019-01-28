#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int isum[100001];
int main()
{
	int n, tmp = 0, sum = 0;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &tmp);	
		if(i>0)isum[i] += tmp+isum[i-1];
		else isum[i] = tmp;
	}
	int m, ttmp;
	scanf(" %d", &m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d %d", &tmp, &ttmp);
		if(tmp == 1) printf("%d\n", isum[ttmp-1]);
		else printf("%d\n", isum[ttmp-1]-isum[tmp-2]);
	}
	return 0;
}