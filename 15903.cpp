#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<lld, vector<lld>, greater<lld> >pq;

	int n, m;
	cin>>n>>m;
	lld tmpa, tmpb;
	for(int i=0;i<n;i++)
	{
		cin>>tmpa;
		pq.push(tmpa);
	}
	for(int i=0;i<m;i++)
	{
		tmpa = pq.top();
		pq.pop();
		tmpb = pq.top();
		pq.pop();
		pq.push(tmpa+tmpb);
		pq.push(tmpa+tmpb);
	}

	lld ans = 0LL;
	while(!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout<<ans;

	return 0;
}