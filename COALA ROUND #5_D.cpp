#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
typedef struct
{
	lld a;
	lld b;
}NUM;
NUM num[25];
bool comp(NUM &s, NUM &k)
{
	return s.b>k.b;
}
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>num[i].a>>num[i].b;
	sort(num, num+m, comp);
	lld sum = 0;
	for(int i=0;i<m;i++)
	{
		if(n==0)
			break;
		if(n>=num[i].a)
		{
			sum += num[i].b*num[i].a;
			n -= num[i].a;
		}
		else
		{
			sum += n*num[i].b;
			break;
		}
	}
	printf("%lld", sum);
	return 0;
}