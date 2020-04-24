#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
 
 
int num[5];
 
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
		for(int i=0;i<4;i++)
		{
			cin>>num[i];
		}
		int l = num[0]-num[1], r = num[0]+num[1];
		int cl = num[2]-num[3], cr = num[2]+num[3];
		if(r*n<cl || l*n>cr)
		{
			cout<<"No"<<endl;
		}
		else cout<<"Yes"<<endl;
	}
	return 0;
}