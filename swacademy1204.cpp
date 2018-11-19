#include <bits/stdc++.h>

using namespace std;


int score[101];

int main()
{
	int t, i, n, j, tmp;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf(" %d", &n);
		for(j=0;j<1000;j++)
		{
			scanf("%d", &tmp);
			score[tmp]++;
		}
		int max = 0, maxi = 0;
		for(j=0;j<101;j++)
		{
			if(max<=score[j])
			{
				max = score[j];
				maxi = j;
			}
		}
		printf("#%d %d\n", n, maxi);
		for(j=0;j<101;j++) score[j] = 0;
	}
	return 0;
}
