#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[81];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %s", s);
		char k = s[0];
		int len = strlen(s);
		int cnt = 0;
		for(int j=0;j<len;j++)
		{
			if(k!=s[j])
			{
				printf("%d %c ", cnt, k);
				k = s[j];
				cnt = 1;
			}
			else cnt++;
			if(j==len-1) printf("%d %c", cnt, k);
		}
		printf("\n");
	}
	return 0;
}