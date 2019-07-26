#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[5];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int checkt = 0;
	int checks = 0;
	for(int i=0;i<4;i++)
		cin>>num[i];
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(k==i || k==j) continue;
				if(num[i]+num[j]>num[k] && num[i]<=num[k] && num[j]<=num[k])
					checkt = 1;
				if(num[i]+num[j]==num[k] && num[i]<=num[k] && num[j]<=num[k])
					checks = 1;

			}
		}
	}
	if(checkt)
		printf("TRIANGLE");
	else if(checks)
		printf("SEGMENT");
	else
		printf("IMPOSSIBLE");
	return 0;
}