# include <bits/stdc++.h>

using namespace std;

int ins [1000001];

int main()
{
	int n, cnt = 0, i, tmp, k = 0;
	scanf("%d", &n);
	if(n==1)
	{
		printf("1 0");
		return 0;
	}
	tmp = n;
	while(tmp != 1)
	{
		for(i=2;i<1000001;i++)
		{
			if(tmp%i == 0)
			{
				ins[i]++;
				tmp = tmp/i;
				break;
			}
		}
	}
	n = 1;
	for(i=2;i<1000001;i++)
	{
		if(ins[i])
		{
			n = n*i;
			k++;
		}
		if(cnt<ins[i]) cnt = ins[i];
	}
	int scnt = 0;
	if(k>1)
	{
		if(cnt>16) tmp = 6;
		if(cnt>8 && cnt <= 16) tmp = 5;
		else if(cnt>4 && cnt<=8) tmp = 4;
		else if(cnt>2 && cnt<=4) tmp = 3;
		else if(cnt == 2) tmp = 2;
		else if(cnt == 1) tmp = 0;
		for(i=0;i<=n;i++)
		{
			if(ins[i] && ins[i] == cnt)
			{
				for(int j=1;j<20;j++)
				{
					if(cnt == pow(2,j))
					{
						scnt++;
					}
				}
			}
		}
		if(scnt == k) tmp--;
	}
	else if(k==1)
	{
		if(cnt>16) tmp = 6;
		if(cnt == 16) tmp = 4;
		else if(cnt>8 && cnt<16) tmp = 5;
		else if(cnt == 8) tmp = 3;
		else if(cnt>4 && cnt<8) tmp = 4;
		else if(cnt == 4) tmp = 2;
		else if(cnt == 3) tmp = 3;
		else if(cnt == 2) tmp = 1;
		else if(cnt == 1) tmp = 0;
	}
	printf("%d %d", n, tmp);
	return 0;
}
