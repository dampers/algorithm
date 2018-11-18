# include <bits/stdc++.h>

using namespace std;

int num[1000001];

int main()
{
	int n, i, m, tmp, j, check, start, end, t, k;
	scanf("%d", &t);
	for(k=0;k<t;k++)
	{
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
			scanf(" %d", &num[i]);
		}
		sort(num, num+n);
		scanf(" %d", &m);
		for(i=0;i<m;i++)
		{
			scanf("%d", &tmp);
			check = n/2;
			start = 0;
			end = n-1;
			while(start<=end)
			{
				check = (start + end)/2;
				if(num[check]<tmp)
				{
					start = check+1;
				}
				else if(num[check]>tmp)
				{
					end = check-1;
				}
				else if(num[check] == tmp)
				{
					printf("1\n");
					break;
				}
			}
			if(start>end) printf("0\n");
		}
	}
	return 0;
}
