#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y;
	cin>>x>>y;
	bool flag = false;
	if(x*y>0) flag = false;
	else if(x*y<0) flag = true;
	else
	{
		cout<<"black";
		return 0;
	}
	double s = pow(x*x+y*y, 0.5);
	for(int i=0;i<1500;i++)
	{
		if(s<i)
		{
			if(!flag && i%2==0)
				cout<<"white";
			else if(!flag && i%2)
				cout<<"black";
			else if(flag && i%2)
				cout<<"white";
			else
				cout<<"black";
			break;
		}
		else if(s==(double)i)
		{
			cout<<"black";
			break;
		}
	}
	return 0;
}