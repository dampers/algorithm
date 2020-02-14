#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct room
{
	lld s;
	lld e;
	bool check;
};

room num[200005];

bool comp(room &a, room &b)
{
	if(a.s==b.s)
		return a.e<b.e;
	return a.s<b.s;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i].s>>num[i].e;
	sort(num, num+n, comp);
	priority_queue <int, vector<int> ,greater<int>> pq;
	pq.push(num[0].e);
	for(int i=1;i<n;i++)
	{
		if(pq.top()>num[i].s) pq.push(num[i].e);
		else
		{
			pq.pop();
			pq.push(num[i].e);
		}
	}
	cout<<pq.size();
	return 0;
}