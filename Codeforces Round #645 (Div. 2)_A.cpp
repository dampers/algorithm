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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, m;
		cin>>n>>m;
		int sum = (m/2)*n;
		if(m%2)
		{
			sum += (n/2)+n%2;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}