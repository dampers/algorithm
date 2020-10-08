#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	lld sum = 1LL;
	if(n==1 || n==2)
	{
		cout<<2;
		return 0;
	}
	if(n%2) n++;
	n /= 2;
	for(int i=0;i<n;i++)
	{
		sum *= 2;
		sum %= 16769023;
	}
	cout<<sum;

	return 0;
}