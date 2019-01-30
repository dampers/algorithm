#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf(" %d", &tmp);
		for(int j=2;j<=tmp;j++)
		{
			int cnt = 0;
			while(tmp%j==0)
			{
				cnt++;
				tmp /= j;
			}
			if(cnt) printf("%d %d\n", j, cnt);
		}
	}
	return 0;
}