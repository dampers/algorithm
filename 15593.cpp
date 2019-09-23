#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool t[1001];
pair<int, int> cow[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, mx = 0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>cow[i].first>>cow[i].second;
	for(int i=0;i<n;i++)
	{
		int cnt = 0;
		for(int ii=0;ii<n;ii++)
		{
			if(ii==i) continue;
			for(int iii=cow[ii].first;iii<cow[ii].second;iii++)
			{
				if(t[iii]) continue;
				t[iii] = true;
				cnt++;
			}
		}
		if(mx<cnt) mx = cnt;
		memset(t, false, sizeof(t));
	}
	cout<<mx;
	return 0;
}