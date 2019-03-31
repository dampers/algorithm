#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;
bool visit[1001];
int check[5];
int ans;
void rome(int pos, int cnt)
{
	int sum = 0;
	if(pos == n)
	{
		sum = check[0]*1+check[1]*5+check[2]*10+check[3]*50;
		//printf("%d\n", sum);
		if(!visit[sum])
		{
		//	printf("check = %d %d %d %d\n", check[0], check[1], check[2], check[3]);
		//	printf("%d\n", sum);
			visit[sum] = true;
			ans++;
			return;
		}
		else
			return;
	}
	for(int i=cnt;i<4;i++)
	{
		if(check[i]<=n)
		{
			check[i]++;
			rome(pos+1, i);
			check[i]--;
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;i++)
	{
		scanf("%d", &n);
		rome(0, 0);
		printf("#%d %d\n",i+1, ans);
		ans = 0;
		memset(visit, false, 1001);
	}

	return 0;
}
