#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int c[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	while(n--)
	{
		int m, k, cnt = 0;
		cin>>m>>k;
		for(int i=0;i<m;i++)
		{
			cin>>c[i];
			cnt += c[i]/k;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}