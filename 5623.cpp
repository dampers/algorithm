#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int num[1001][1001];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>num[i][j];
		}
	}
	if(n==2)
	{
		cout<<num[0][1]-1<<' '<<1;
		return 0;
	}
	int a = (num[0][1]+num[0][2]-num[1][2])/2;
	cout<<a<<' ';
	for(int i=1;i<n;i++)
		cout<<num[0][i]-a<<' ';
	return 0;
}