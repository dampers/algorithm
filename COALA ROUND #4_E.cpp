#include <bits/stdc++.h>
using namespace std;
int price[105];
char tmp[105];
typedef struct
{
	char fr[105];
	int cnt = 0;
}Fruit;
Fruit fruit[105];

bool comp(Fruit &a, Fruit &b)
{
		return a.cnt>b.cnt;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		scanf(" %d", &price[i]);
	sort(price, price+n);
	int size = 0;
	for(int i=0;i<m;i++)
	{
		scanf(" %s", tmp);
		bool flag = false;
		for(int j=0;j<size;j++)
		{
			if(strcmp(fruit[j].fr, tmp)==0)
			{
				fruit[j].cnt++;
				flag = true;
				break;
			}
		}
		if(flag)
			continue;
		strcpy(fruit[size].fr, tmp);
		fruit[size].cnt = 1;
		size++;
	}
	sort(fruit, fruit+size, comp);
	int mn = 0;
	for(int i=0;i<size;i++)
	{
		mn += fruit[i].cnt * price[i];
	}
	int mx = 0;
	reverse(price, price+n);
	for(int i=0;i<size;i++)
	{
		mx += fruit[i].cnt * price[i];
	}
	printf("%d %d", mn, mx);
	return 0;
}
