#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int wood[6];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++)
		cin>>wood[i];
	for(int i=0;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(wood[j]<wood[j-1])
			{
				int tmp = wood[j];
				wood[j] = wood[j-1];
				wood[j-1] = tmp;
				for(int k=0;k<5;k++)
					cout<<wood[k]<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}