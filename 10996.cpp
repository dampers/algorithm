#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"*";
		return 0;
	}
	int k = n%2?n/2+1:n/2;
	for(int i=1;i<=n;i++)
	{

		for(int j=0;j<k;j++)
		{
			cout<<"* ";
		}
		cout<<endl<<' ';
		for(int j=0;j<n/2;j++)
		{
			cout<<"* ";
		}
		cout<<endl;
	}
	return 0;
}