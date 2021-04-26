#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<pair<lld, lld>> mv(n);
	vector<lld> c(k);
	for(int i=0;i<n;i++)
		cin >> mv[i].first >> mv[i].second;
	for(int i=0;i<k;i++)
		cin >> c[i];
	sort(mv.begin(), mv.end());
	sort(c.begin(), c.end());
	lld ans = 0LL;
	int idx = 0;
	priority_queue<lld, vector<lld>, less<lld>> pq;
	for(int i=0;i<k;i++)
	{
		while(idx<n && mv[idx].first<=c[i])
		{
			pq.push(mv[idx++].second);
		}
		if(pq.size())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;

	return 0;
}