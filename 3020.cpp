#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int uf[500005], df[500005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, h;
	cin>>n>>h;
	int umx = 0, dmx = 0;
	for(int i=0;i<n/2;i++)
	{
		int uu, dd;
		cin>>dd>>uu;
		df[dd]++;
		uf[uu]++;
	}
	for(int i=h;i>=1;i--)
	{
		uf[i] += uf[i+1];
		df[i] += df[i+1];
	}
	for(int i=1;i<=h;i++)
		df[i] += uf[h-i+1];
	int kmn = df[1], cnt = 1;
	for(int i=2;i<=h;i++)
	{
		if(kmn>df[i])
		{
			kmn = df[i];
			cnt = 1;
		}
		else if(kmn==df[i]) cnt++;
	}
	cout<<kmn<<' '<<cnt;
	return 0;
}