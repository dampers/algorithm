# include <bits/stdc++.h>

using namespace std;

int card[500001];
int cnt[20000006];
int n;

int bs(int s)
{
	int center, front, back;
	front = 0;
	back = n-1;
	while(1)
	{
		center = (front+back)/2;
		if(s>card[center]) front = center+1;
		else if(s<card[center]) back = center-1;
		else if(s == card[center]) return 1;
		if(front>back) return 0;
	}
}

int main()
{
	int m;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &card[i]);
		if(card[i]>0) cnt[card[i]+10000000]++;
		else cnt[card[i]*-1]++;
	}
	sort(card, card+n);
	scanf(" %d", &m);
	int s;
	for(int i=0;i<m;i++)
	{
		scanf(" %d", &s);
		if(bs(s) == 1)
		{
			if(s>0) s += 10000000;
			else s *= -1;
			printf("%d ", cnt[s]);
		}
		else printf("0 ");
	}
	return 0;
}
