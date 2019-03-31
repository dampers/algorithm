#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int door[200001];
int main()
{
	int n, ld = 0, rd = 0;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &door[i]);
		if(door[i]==0) ld = i;
		else rd = i;
	}
	int sh = min(ld, rd);
	printf("%d", sh+1);
	return 0;
}