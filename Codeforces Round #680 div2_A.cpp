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
		int n, x;
		cin>>n>>x;
		vector<int> a(n, 0), b(n, 0);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			if(a[i]+b[i]>x) flag = true;
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}