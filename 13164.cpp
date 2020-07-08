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
	int n, k;
	cin>>n>>k;
	vector<int> v(n), h(n-1);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n-1;i++)
	{
		h[i] = v[i+1]-v[i];
	}
	sort(h.begin(), h.end());
	lld sum = 0LL;
	for(int i=0;i<n-k;i++)
	{
		sum += h[i];
	}
	cout<<sum;
	return 0;
}

