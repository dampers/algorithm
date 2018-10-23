# include <stdio.h>

int num[1001];

int main()
{
	int n, i, tmp = 0, max = 0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &num[i]);
		if(i>0)
		{
			if(num[i-1]<num[i]) tmp += num[i]-num[i-1];
			else tmp = 0;
			if(max<tmp) max = tmp;
		}
	}
	printf("%d", max);
	return 0;
}
