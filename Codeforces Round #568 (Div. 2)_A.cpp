#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[5];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<3;i++)
	{
		cin>>num[i];
	}
	int d;
	cin>>d;
	int cnt = 0;
	sort(num, num+3);
	if(d-abs(num[2]-num[1])>0)
		cnt+=d-abs(num[2]-num[1]);
	if(d-abs(num[1]-num[0])>0)
		cnt+=d-abs(num[1]-num[0]);
	printf("%d", cnt);
	return 0;
}