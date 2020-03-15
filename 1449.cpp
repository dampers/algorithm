#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[1002];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin>>n>>l;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		check[tmp] = true;
	}
	int ans = 0;
	for(int i=1;i<1002;i++)
	{
		if(check[i])
		{
			i += l-1;
			ans += 1;
		}
	}
	cout<<ans;
	return 0;
}