#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char sa[105];
char sb[105];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf("%d", &n);
	scanf(" %s %s", sa, sb);
	int cnt = 0;
	for(int i=0;i<n;i++) if(sa[i]=='C' && sb[i]=='C') cnt++;
	printf("%d", cnt);
	return 0;
}