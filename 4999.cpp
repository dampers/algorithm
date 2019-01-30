#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char ja[1005], doc[1005];
int main()
{
	scanf(" %s %s", ja, doc);
	int lenj = strlen(ja);
	int lend = strlen(doc);
	if(lend<=lenj) printf("go");
	else printf("no");
	return 0;
}