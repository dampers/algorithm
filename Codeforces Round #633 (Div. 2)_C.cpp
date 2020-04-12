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
		bool flag = true;
		//vector<lld> v;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			if(i>0 && num[i-1]>num[i])
			{
				flag = false;
				//v.push_back(num[i-1]-num[i]);
			}
		}
		if(flag)
		{
			cout<<0<<endl;
			continue;
		}
		lld x = 1LL, kmx = num[0];
		int cnt = 1;
		for(int i=1;i<n;i++)
		{
			if(num[i]<kmx)
			{
				lld tmp = kmx-num[i];
				int kcnt = 0;
				while(tmp)
				{
					tmp /= 2;
					kcnt++;
				}
				if(cnt<kcnt) cnt = kcnt;
			}
			if(kmx<num[i]) kmx = num[i];
		}
		cout<<cnt<<endl;
	}
	return 0;
}