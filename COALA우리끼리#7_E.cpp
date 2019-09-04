#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char s[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, b;
	scanf("%d %s %d",&n, s, &b);
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		if(!flag && s[i]=='0') continue;
		else if(!flag) flag = true;
		if(flag)
			printf("%c", s[i]);
	}
	if(!flag)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<b;i++)
		printf("0");
	return 0;
}