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
	int a;
	cin>>a;
	int ind = 0;
	while(1)
	{
		int tmp = a;
		ind = 0;
		while(tmp)
		{
			num[ind] = tmp%10;
			tmp /= 10;
			ind++;
		}
		reverse(num, num+ind);
		int sum = 0;
		for(int i=0;i<ind;i++)
		{
			sum += num[i];
		}
		if(sum%4==0)
		{
			for(int i=0;i<ind;i++)
				printf("%d", num[i]);
			return 0;
		}
		a++;
	}
	return 0;
}