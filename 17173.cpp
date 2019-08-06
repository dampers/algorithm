#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int k[1005];
bool check[1005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>k[i];
	lld sum = 0;
	for(int i=0;i<m;i++)
	{
		int tmp = k[i];
		while(tmp<=n)
		{
			if(!check[tmp])
			{
				sum += tmp;
				check[tmp] = true;
			}
			tmp += k[i];

		}
	}
	cout<<sum;
	return 0;
}