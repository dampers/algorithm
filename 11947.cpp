#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[20];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc, tmp;
	scanf(" %d", &tc);
	while(tc--)
	{
		scanf(" %s", s);
		//printf("%s\n", s);
		int len = strlen(s);
		lld a = 0, b = 0, cnt = 0;
		for(int i=len-1;i>=0;i--)
		{
			tmp = (int)s[i]-'0';
			a += pow(10, cnt)*tmp;
			b += abs(9-tmp)*pow(10, cnt);
			cnt++;
		}
		printf("%lld\n", a*b);
	}
	return 0;
}