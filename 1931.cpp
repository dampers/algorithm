#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct room
{
	lld s;
	lld e;
	lld c;
};

room num[100005];

bool comp(room &a, room &b)
{
	if(a.e==b.e)
		return a.s<b.s;
	return a.e<b.e;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	lld mx = 0;
	for(int i=0;i<n;i++)
	{
		cin>>num[i].s>>num[i].e;
		mx = max(num[i].e, mx);
	}
	sort(num, num+n, comp);
	lld start = 0, cnt = 0;
	bool flag = true;
	for(int i=0;i<n;i++)
	{
		if(num[i].s>=start)	
		{
			cnt++;
			start = num[i].e;
		}
		else continue;
	}
	cout<<cnt;
	return 0;
}