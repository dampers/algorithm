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
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp!=i) cnt++;
	}
	cout<<cnt;
	return 0;
}