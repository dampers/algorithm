#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[200001];
int cnt[200001];
int main()
{
	int n;
	scanf("%d", &n);
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &num[i]);
		cnt[num[i]]++;
		if(cnt[num[i]]>2)
		{
			flag = 1;
		}
	}
	if(flag)
	{
		printf("NO");
		return 0;
	}
	int ccnt = 0;
	for(int i=0;i<200001;i++)
	{
		if(cnt[i]==2)
		{	
			ccnt++;
		}
	}
	printf("YES\n");
	printf("%d\n", ccnt);
	ccnt = 0;
	for(int i=0;i<200001;i++)
	{
		if(cnt[i]==2)
		{	
			printf("%d ", i);
			cnt[i]--;
		}
	}
	for(int i=0;i<200001;i++)
	{
		if(cnt[i]==1)
		{	
			ccnt++;
		}
	}
	printf("\n%d\n", ccnt);
	for(int i=200001;i>=0;i--)
	{
		if(cnt[i]==1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}