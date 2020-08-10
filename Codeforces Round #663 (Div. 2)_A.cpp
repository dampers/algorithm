
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
		int n;
		cin>>n;
		for(int i=n;i>=1;i--)
			cout<<i<<" ";
		cout<<endl;
	}
	
	return 0;
}