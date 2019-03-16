#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int acid[100001];
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &acid[i]);
	}
	sort(acid, acid+n);
	int start = 0, end = n-1;
	int ans = abs(acid[end]+acid[start]), sum;
	int ac = acid[end], al = acid[start];
	while(start<end && end>0 && start<n-1)
	{
		sum = acid[end]+acid[start];
		if(abs(sum)<ans)
		{
			ans = abs(sum);
			ac = acid[end];
			al = acid[start];
			//printf("sum = %d ac = %d al = %d\n", sum, ac, al);
		}
		if(sum>0)
		{
			end--;
		}
		else if(sum<0)
		{
			start++;
		}
		else
		{
			break;
		}
	}
	printf("%d %d", al, ac);
	return 0;
}