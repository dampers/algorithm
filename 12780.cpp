#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[100002];
char a[12];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf(" %s %s", s, a);
	int len = strlen(s);
	int alen = strlen(a);
	int cnt = 0;
	for(int i=0;i<len-alen+1;i++)
		if(!strncmp(s+i, a, alen)) cnt++;
	printf("%d", cnt);
	return 0;
}