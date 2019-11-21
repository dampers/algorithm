#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[105];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>num[i];
		if(n==2)
		{
			if(abs(num[0]-num[1])<=1) cout<<2<<endl;
			else cout<<1<<endl;
			continue;
		}
		else if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		int mx = 0;
		int ucnt = 0, dcnt = 0, s = 0;
		for(int i=0;i<n;i++)
		{
			ucnt = 0;
			dcnt = 0;
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;
				if(abs(num[i]-num[j])<=1)
				{
					if(num[i]>num[j])
						dcnt++;
					else if(num[i]<num[j])
						ucnt++;
					else s++;

				}
			}
			mx = max(mx, ucnt);
			mx = max(mx, dcnt);
			mx = max(mx, s);
		}
		cout<<mx+1<<endl;
		memset(num, 0, sizeof(num));
	}
	
	return 0;
}