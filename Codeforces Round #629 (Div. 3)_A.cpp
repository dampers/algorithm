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
		int a, b;
		cin>>a>>b;
		int tmp = ((a/b+1)*b)-a;
		if(a%b==0) cout<<0<<endl;
		else cout<<tmp<<endl;
	}
	return 0;
}