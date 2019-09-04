#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
lld num[100005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		lld tmp;
		cin>>tmp;
		num[i] = num[i-1]+tmp;
	}
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		cout<<num[b]-num[a-1]<<endl;
	}
	return 0;
}