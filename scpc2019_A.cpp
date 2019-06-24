#include <iostream>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
lld num[1000001];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	lld cnt = 1;
	lld ccnt = 0;
	for(int i=2;i<1000000;i*=2)
	{
		num[i] = cnt;
		cnt++;
		num[i-1] = cnt;
	}
	num[1] = 0;
	for(int i=3;i<=1000000;i++)
	{
		cnt = 0;
		int k = i;
		if(num[i]!=0)
		{
			continue;
		}
		while(k>1)
		{
			cnt++;
			if(k%2) k++;
			else k/=2;
		}
		num[i] = cnt;
	}
	for(int i=2;i<=1000000;i++)
	{
		num[i] += num[i-1];
		//printf("num[%d] = %lld\n", i, num[i]);
	}
	cnt = 0;
	int t, n, m;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n>>m;
		cout<<"Case #"<<z<<"\n"<<num[m]-num[n-1]<<endl;
	}
	return 0;
}
