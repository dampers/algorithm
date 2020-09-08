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
 
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		bool flag = true;
		for(int i=1;i<n;i++)
		{
			if(v[i]-v[i-1]>1)
			{
				//cout<<v[i]<<' '<<v[i-1]<<endl;
				flag = false;
				break;
			} 
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}