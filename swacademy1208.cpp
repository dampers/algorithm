#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int box[104];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int tc=1;tc<=10;tc++)
	{
		int dump = 0;
		cin>>dump;
		for(int i=0;i<100;i++)
			cin>>box[i];
		int mn = 108, mx = 0, nn = 0;
		for(int j=0;j<=dump;j++)
		{
			int mx = 0, nn = 0;
			for(int i=0;i<100;i++)
			{
				if(box[mx]<box[i]) mx = i;
				if(box[nn]>box[i]) nn = i;
			}
			mn = box[mx]-box[nn];
			if(box[mx]-box[nn]==0)
			{
				mn = box[mx]-box[nn];
				break;
			}
			box[mx]--;
			box[nn]++;
		}
		cout<<"#"<<tc<<' '<<mn<<endl;
	}
	return 0;
}