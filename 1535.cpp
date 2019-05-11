#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

pair<int, int> person[21];
int happy = 0;
int hp = 100;
int tmp = 0;
int n;
bool visit[21];
void hello(int pos, int k, int mx)
{
	if(pos==mx)
	{
		if(tmp>happy) happy = tmp;
		//printf("hp = %d, tmp = %d\n", hp, tmp);
		return;
	}
	for(int i=k;i<n;i++)
	{
		if(visit[i]==false && hp-person[i].first>0)
		{
			visit[i] = true;
			hp -= person[i].first;
			tmp += person[i].second;
			//printf("hp = %d, tmp = %d\n", hp, tmp);
			hello(pos+1, i, mx);
			hp += person[i].first;
			tmp -= person[i].second;
			visit[i] = false;
		}
	}
}

int main()
{
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &person[i].first);
	for(int i=0;i<n;i++)
		scanf("%d", &person[i].second);
	for(int i=1;i<=n;i++)
	{
		tmp = 0;
		hello(0, 0, i);
	}
	printf("%d", happy);
	return 0;
}
