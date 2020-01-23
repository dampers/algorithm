#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[50005];
int sqnum[250];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<224;i++)
	{
		num[i*i] = 1;
		sqnum[i] = i*i;
	}
	if(num[n])
	{
		cout<<num[n];
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(num[i]) continue;
		num[i] = 4;
		for(int j=1;sqnum[j]<i;j++)
		{
			num[i] = min(num[i-sqnum[j]]+1, num[i]);
		}
	}
	cout<<num[n];
	return 0;
}