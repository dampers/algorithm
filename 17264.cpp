#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char tmp[24];
typedef struct
{
	char name[24];
	char p;
}HACK;
HACK hack[1001];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p;
	scanf("%d %d", &n, &p);
	int w, l, g;
	scanf("%d %d %d", &w, &l, &g);
	for(int i=0;i<p;i++)
		scanf(" %s %c", hack[i].name, &hack[i].p);
	bool flag = false;
	int point = 0;
	for(int i=0;i<n;i++)
	{
		flag = false;
		scanf(" %s", tmp);
		for(int j=0;j<p;j++)
		{
			if(!strcmp(hack[j].name, tmp))
			{
				flag = true;
				if(hack[j].p == 'W') point += w;
				else if(hack[j].p=='L') point -= l;
				break;
			}
		}
		if(point>=g)
		{
			printf("I AM NOT IRONMAN!!");
			return 0;
		}
		if(!flag)
			point -= l;
		point = max(0, point);
	}
	printf("I AM IRONMAN!!");
	return 0;
}