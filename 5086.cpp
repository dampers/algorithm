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
	while(1)
	{
		int a, b;
		cin>>a>>b;
		if(a==0 && b==0) break;
		if(b%a==0) cout<<"factor\n";
		else if(a%b==0) cout<<"multiple\n";
		else cout<<"neither\n";
	}
	return 0;
}