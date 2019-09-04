#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[101];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		int umx = 0, dmx = 0;
		for(int i=0;i<n-1;i++)
		{
			if(num[i]>num[i+1])
				dmx = max(dmx, num[i]-num[i+1]);
			else
				umx = max(umx, num[i+1]-num[i]);
		}
		cout<<"#"<<tc<<' '<<umx<<' '<<dmx<<endl;
	}
	return 0;
}