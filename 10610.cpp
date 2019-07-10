#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char num[100004];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int ind = 0, zcnt = 0;
	scanf("%s", num);
	int sum = 0;
	ind = strlen(num);
	for(int i=0;i<ind;i++)
	{
		if(num[i]=='0') zcnt++;
		sum += (int)(num[i]-'0');
	}
	if(sum%3==0 && zcnt)
	{
		sort(num, num+ind);
		reverse(num, num+ind);
		for(int i=0;i<ind;i++)
			printf("%c", num[i]);
	}
	else
		printf("-1");
	return 0;
}