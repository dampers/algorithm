#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> a(n), l(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>l[i];
		priority_queue<int, vector<int>> pq;
		for(int i=0;i<n;i++)
		{
			if(l[i]==0)
			{
				pq.push(a[i]);
				//cout<<a[i]<<endl;
			}
		}
		lld sum = 0LL;
		for(int i=0;i<n;i++)
		{
			if(l[i]==0)
			{
				a[i] = pq.top();
				pq.pop();
			}
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}