#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int b[55];
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int a, d = 0;
		scanf(" %d", &a);
		for(int j=0;j<a;j++) scanf(" %d", &b[j]);
		for(int j=0;j<a-1;j++) if(j+1<=a && b[j]>=b[j+1]) d++;
		printf("Case #%d: %d\n", i+1, d);
	}
	return 0;
}