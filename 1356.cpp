#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld num[101];
int main()
{
	lld tmp, ind = 0;
	while(scanf("%1lld", &tmp)==1)
	{
		num[ind] = tmp;
		ind++;
	}
	lld ans1 = 1, ans2 = 1;
	bool flag = false;
	for(int i=0;i<ind-1;i++)
	{
		ans1 = 1;
		ans2 = 1;
		for(int j=0;j<=i;j++)
			ans1 *= num[j];
		for(int j=i+1;j<ind;j++)
			ans2 *= num[j];
		if(ans1==ans2)
		{
			flag = true;
			break;
		}
		//printf("%lld %lld\n", ans1, ans2);
	}
	if(flag) printf("YES");
	else printf("NO");
	return 0;
}