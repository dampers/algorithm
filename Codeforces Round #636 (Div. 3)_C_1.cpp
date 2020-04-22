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
	vector<lld> num;
	while(tc--)
	{
		int n;
		cin>>n;
		num.resize(n);
		int plen = 0, mlen = 0;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		}
		bool flag = num[0]>0?false:true;
		lld mx = 0LL, mn = -2e9, sum = 0LL;
		for(int i=0;i<n;i++)
		{
			//cout<<"num["<<i<<"] = "<<num[i]<<endl;
			if(num[i]>0)
			{
				if(!flag)
				{
					mx = max(mx, num[i]);
				}
				else
				{
					sum += mn;
					mx = num[i];
					mn = -2e9;
					flag = false;
					mlen--;
				}
			}
			else
			{
				if(!flag)
				{
					sum += mx;
					mx = 0LL;
					mn = num[i];
					flag = true;
					plen--;
				}
				else
				{
					mn = max(mn, num[i]);
				}
			}
			///cout<<mx<<' '<<mn<<endl;
			//cout<<"sum = "<<sum<<endl;
		}
		if(mn!=-2e9) sum += mn;
		else if(mx!=0LL) sum += mx;
		cout<<sum<<endl;

	}
	
	return 0;
}