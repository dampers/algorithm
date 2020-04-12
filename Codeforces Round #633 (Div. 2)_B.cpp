#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

lld num[100005];

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
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		}
		sort(num, num+n);
		vector<lld> v;
		for(int i=0;i<n/2;i++)
			{
				v.push_back(num[i]);
				v.push_back(num[n-i-1]);
			}
		if(n%2) v.push_back(num[n/2]);
		reverse(v.begin(), v.end());
		int size = v.size();
		for(int i=0;i<size;i++)
		{
			cout<<v[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}