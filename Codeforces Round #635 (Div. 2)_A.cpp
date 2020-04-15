#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[5];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		for(int i=0;i<4;i++)
		{
			cin>>num[i];
		}
		cout<<num[1]<<' '<<num[2]<<' '<<num[2]<<endl;
	}
	
	return 0;
}