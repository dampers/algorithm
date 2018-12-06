#include <bits/stdc++.h>
using namespace std;
int b[8001];
int main()
{
	int i,j,t,n,sum=0,cnt=0;
	int maxim=0, min=0, temp=0;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		sum+=a[i];
		b[a[i]+4000]++;
	}
	sort(a, a+n);
	maxim=a[n-1];
	min=a[0];
	printf("%d\n", (int)floor((double)sum/n+0.5));
	printf("%d\n", a[n/2]);
	int max=b[0];
	for(i=1; i<=8000; i++)
		if(b[i]!=0)
			if(b[i] > max)
			{
				max=b[i];
				temp=i;				
			}			
	for(i=1; i<=8000; i++)
	{
		if(b[i]==max)
			{
				cnt++;
				if(cnt==2)
				{
					printf("%d\n", i-4000);
					break;
				}
			}
	}
	if(cnt==1)
		printf("%d\n", temp-4000);		
	
	printf("%d", maxim-min);
	return 0;
}
