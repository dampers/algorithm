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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<pair<lld, lld>> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i].first;
		for(int i=0;i<n;i++)
			cin>>v[i].second;
		lld left = 1, right = (lld)1e9;
		lld sum = 0LL;
		while(left<right)
		{
			int mid = (left+right)/2; // time
			lld sum = 0LL;
			for(int i=0;i<n;i++)
			{
				if(v[i].first>mid) sum += v[i].second;
			}
			if(sum>mid) left = mid+1;
			else right = mid;
		}
		cout<<left<<endl;
	}
	return 0;
}