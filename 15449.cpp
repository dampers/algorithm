#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int stick[6];
int main()
{
	for(int i=0;i<5;i++)
	{
		scanf(" %d", &stick[i]);
	}
	int cnt = 0;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<5;j++)
		{
			int sum = 0;
			if(i>=j)
				continue;
			sum = stick[i]+stick[j];
			for(int k=0;k<5;k++)
			{
				if(i==k||j==k)
					continue;
				if(sum>stick[k]&&(max(stick[i], stick[j])<=stick[k]))
					cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}