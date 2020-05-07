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
	for(int i=0;i<n;i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		if(x1==x2 && y1==y2 && r1==r2) cout<<-1<<endl;
		else
		{
			int dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
			int ld = (r1+r2)*(r1+r2), sd = (r1-r2)*(r1-r2);
			if(dis>ld) cout<<0<<endl;
			else if(dis==ld) cout<<1<<endl;
			else if(dis<ld && dis>sd) cout<<2<<endl;
			else if(dis==sd) cout<<1<<endl;
			else if(dis<sd) cout<<0<<endl;
		}
	}
	return 0;
}