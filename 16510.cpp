#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld task[200005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		lld tmp;
		cin>>tmp;
		if(i>0) task[i] = tmp+task[i-1];
		else task[i] = tmp;
	}
	for(int i=0;i<m;i++)
	{
		lld t;
		cin>>t;
		int l = 0, r = n-1;
		while(l<r)
		{
			int mid = (l+r)/2;
			if(task[mid]>t) r = mid-1;
			else if(task[mid]<t) l = mid+1;
			else
			{
				l = mid;
				break;
			}
		}
		while(task[l]>t) l--;
		cout<<l+1<<'\n';
	}
	return 0;
}