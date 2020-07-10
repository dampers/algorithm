#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first < b.second.first;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int, pair<int, int>>> v(n);
	for(int i=0;i<n;i++)
	{
		v[i].first = i+1;
		cin>>v[i].second.first>>v[i].second.second;
	}
	sort(v.begin(), v.end(), comp);
	priority_queue<int> pq;
	int ans = 0, mx = 0;
	for(int i=0;i<n;i++)
	{
		while(!pq.empty() && -pq.top()<v[i].second.first) pq.pop();
		pq.push(-v[i].second.second);
		if(ans<(int)pq.size())
		{
			ans = (int)pq.size();
			mx = v[i].second.first;
		}
	}
	vector<int> clp;
	for(int i=0;i<n;i++)
	{
		if(v[i].second.first<=mx && mx <= v[i].second.second) clp.push_back(v[i].first);
	}
	cout<<ans<<endl;
	for(int i=0;i<(int)clp.size();i++)
		cout<<clp[i]<<" ";
	return 0;
}
