#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool onit[101];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	queue<int> q[101];
	vector<int> v;
	for(int i=0;i<k;i++)
	{
		int tmp;
		cin>>tmp;
		q[tmp].push(i);
		v.push_back(tmp);
	}
	vector<int> tap;
	int cnt = 0, size = 0;
	for(int i=0;i<k;i++)
	{
		if(onit[v[i]])
		{
			if(!q[v[i]].empty()) q[v[i]].pop();
			continue;
		}
		if(size<n)
		{
			tap.push_back(v[i]);
			if(!q[v[i]].empty()) q[v[i]].pop();
			onit[v[i]] = true;
			size++;
		}
		else
		{
			cnt++;
			int ind = -1, mx = 0;
			for(int j=0;j<size;j++)
			{
				if(q[tap[j]].empty())
				{
					ind = j;
					break;
				}
				else if(mx<q[tap[j]].front())
				{
					ind = j;
					mx = q[tap[j]].front();
				}
			}
			onit[tap[ind]] = false;
			tap[ind] = v[i];
			onit[v[i]] = true;
			q[v[i]].pop();
		}
	}
	cout<<cnt;
	return 0;
}