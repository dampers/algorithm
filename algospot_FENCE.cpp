#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int solve(int left, int right, vector<int>& v)
{
	if(left==right) return v[left];
	int mid = (left+right)/2;
	int ret = max(solve(left, mid, v), solve(mid+1, right, v));
	int lo = mid, hi = mid+1, height = min(v[lo], v[hi]);
	ret = max(ret, height+height);
	while(left<lo || hi<right)
	{
		if(hi<right && (lo==left || v[lo-1]<v[hi+1]))
		{
			hi++;
			height = min(height, v[hi]);
		}
		else
		{
			lo--;
			height = min(height, v[lo]);
		}
		ret = max(ret, height*(hi-lo+1));
	}
	return ret;
}

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
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<solve(0, n-1, v)<<endl;
	}
	return 0;
}