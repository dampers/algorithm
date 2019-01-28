#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int d[200];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	sort(d, d+n);
	int x = d[n-1], y;
	for(int i=1;i<=d[n-1]/2;i++)
	{
		if(d[n-1]%i==0)
		{
			for(int j=0;j<n;j++)
			{
				if(d[j]==i)
				{
					d[j] = 0;
					break;
				}
			}
		}
	}
	sort(d, d+n);
	y = d[n-2];
	printf("%d %d", x, y);
	return 0;
}