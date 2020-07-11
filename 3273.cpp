#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int x;
	cin>>x;
	sort(v.begin(), v.end());
	int l = 0, r = n-1, cnt = 0;
	while(l<r)
	{
		if(v[l]+v[r]>x) r--;
		else if(v[l]+v[r]<x) l++;
		else
		{
			cnt++;
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
