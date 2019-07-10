#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<3;i++)
		cin>>num[i];
	sort(num, num+3);
	if(num[2]-num[1]==num[1]-num[0])
		cout<<num[2]+(num[2]-num[1]);
	else
	{
		if(num[2]-num[1]>num[1]-num[0])
			cout<<num[2]-(num[1]-num[0]);
		else
			cout<<num[1]-(num[2]-num[1]);
	}
	return 0;
}