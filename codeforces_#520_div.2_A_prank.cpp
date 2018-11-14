# include <bits/stdc++.h>

using namespace std;

int num[101];

int main()
{
	int n, i, max = 0, cnt = 0;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf(" %d", &num[i]);
		if(i>1)
		{
			if(num[i]-num[i-1] == 1)
			{
				cnt++;
			}
			else if(num[i]-num[i-1]>1)
			{
				cnt = 0;
			}
			if(num[i]-num[1] == cnt && num[1] == 1)
			{
				max = cnt;
			}
			else if(num[i]-num[i-cnt]== cnt && max<cnt-1)
			{
				max = cnt-1;
			}
		}
	}
	if(num[n] == 1000 && 1000-cnt == num[n-cnt] && max<=cnt)
	{
		max = cnt;
	}
	printf("%d", max);
	return 0;
}	
