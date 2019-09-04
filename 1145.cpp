#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[6];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++)
		cin>>num[i];
	for(int i=2;;i++)
	{
		int check = 0;
		for(int j=0;j<5;j++)
			if(i%num[j]==0)
				check++;
		if(check>=3)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}