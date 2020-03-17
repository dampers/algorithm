#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++)
	{
		int s, t;
		cin>>s>>t;
		v.push_back({s, t});
	}
	sort(v.begin(), v.end(), comp);
	priority_queue<int, vector<int>, greater<int>> pq;
	int cnt = 1;
	pq.push(v[0].second);
	for(int i=1;i<n;i++)
	{
		if(v[i].first>=pq.top()) pq.pop();
		else cnt++;
		pq.push(v[i].second);
	}
	cout<<cnt;
	return 0;
}