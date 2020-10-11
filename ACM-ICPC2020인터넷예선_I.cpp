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
	int n;
	cin>>n;
	vector<int> v(n*2);
	for(int i=0;i<2*n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	lld mn = v[0]+v[2*n-1];
	for(int i=0;i<n;i++)
	{
		if(mn>v[i]+v[2*n-i-1]) mn = v[i]+v[2*n-i-1];
	}
	cout<<mn;
	return 0;
}