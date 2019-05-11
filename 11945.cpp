#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char s[15];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
	{
		scanf(" %s", s);
		reverse(s, s+m);
		printf("%s\n", s);
	}
	return 0;
}