#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int a[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		a[tmp]++;
	}
	int mx = 0;
	for(int i=1;i<=3;i++)
		mx = max(a[i], mx);
	if(mx==a[1])
		cout<<a[2]+a[3];
	else if(mx==a[2])
		cout<<a[1]+a[3];
	else if(mx==a[3])
		cout<<a[1]+a[2];
	return 0;
}