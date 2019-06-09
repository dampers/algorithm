#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l = 0;
		lld n;
		cin>>n;
		int cnt = 0;
		bool tflag = false;
		while(1)
		{
			if(n==1)
			{
				tflag = true;
				break;
			}
			if(l>100) break;
			l++;
			if(n%2==0)
			{
				n /= 2;
				cnt++;
			}
			if(n%3==0)
			{
				n = (n*2)/3;
				cnt++;
			}
			if(n%5==0)
			{
				n = (n*4)/5;
				cnt++;
			}
		}
		if(n==1) printf("%d\n", cnt);
		else printf("-1\n");
	}
	return 0;
}
