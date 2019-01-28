#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char d[1001];
int main(){
	int n;
	scanf(" %d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf(" %s", d);
		int len = strlen(d);
		if(d[len/2-1]==d[len/2]) printf("Do-it\n");
		else printf("Do-it-Not\n");
	}
	return 0;
}