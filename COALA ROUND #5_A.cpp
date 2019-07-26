#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char s[5][5];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<3;i++)
		scanf(" %s", s[i]);
	if(s[0][0]==s[2][2] && s[0][1]==s[2][1] && s[0][2]==s[2][0] && s[1][0] == s[1][2])
		printf("YES");
	else
		printf("NO");
	return 0;
}