# include <bits/stdc++.h>
using namespace std;
int tree[1000001];
int main()
{
	int n, m, p;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) scanf(" %d", &tree[i]);
	int l = 0, r = 1000000000;
	while(l<r)
	{
		int c = (l+r)/2;
		long long sum = 0;
		for(int i=0;i<n;i++)
		{
			sum += tree[i]-c<0?0:tree[i]-c;
		}
		if(m==sum)
		{
			p = c;
			break;
		}
		else if(m>sum)
		{
			r = c-1;
		}
		else if(m<sum)
		{
			l = c+1;
			p = l-1;
		}
	}
	printf("%d", p);
	return 0;
}