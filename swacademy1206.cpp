#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int view[1005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int t=0;t<10;t++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>view[i];
		int cnt = 0;
		for(int i=2;i<n-2;i++)
		{
			int tmp = 1000;
			for(int j=-2;j<3;j++)
			{
				if(j==0) continue;
				if(view[i]<=view[i+j])
				{
					tmp = 0;
					break;
				}
				else tmp = min(tmp, view[i]-view[i+j]);
			}
			cnt += tmp;
		}
		cout<<"#"<<t+1<<' '<<cnt<<endl;
	}
	return 0;
}