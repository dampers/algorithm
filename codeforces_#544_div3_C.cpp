#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[200001];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &num[i]);
	}
	sort(num, num+n);
	int mx = 1, tmp = 1, mnum = num[0], id = 0;
	for(int i=1;i<n;i++)
	{
		if(abs(mnum-num[i])<=5)
		{
			tmp++;
		}
		else
		{
			for(int j = id+1;j<=i;j++)
			{
				if(abs(num[i]-num[j])<=5)
				{
					mnum = num[j];
					id = j;
					break;
				}
				else
					tmp--;
			}
		}
		if(mx<tmp) mx = tmp;
	}
	printf("%d", mx);
	return 0;
}