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
	vector<int> v(1, 0);
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		if(v.back()<tmp) v.push_back(tmp);
		else *lower_bound(v.begin(), v.end(), tmp) = tmp;
	}
	cout<<v.size()-1;
	return 0;
}