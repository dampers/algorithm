# include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, i, ang;
	float tmp;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d", &ang);
		int flag = 0;
		for(int j=3;j<=998244353;j++)
		{
			tmp = 1.0*(180*(j-2))/j;
			if(ang == tmp)
			{
				printf("%d\n", j);
				break;
			}
			tmp = 1.0*(180-tmp)/2;
			for(int k=1;k<=j-3;k++)
			{
				if(tmp*k>ang) break;
				if(ang == tmp*k)
				{
					printf("%d\n", j);
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
	}
	return 0;
}
