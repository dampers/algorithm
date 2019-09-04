#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int tcnt = 0, fcnt = 0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int tmp = i;
		while(tmp>1)
		{
			if(tmp%2==0)
			{
				tcnt++;
				tmp /= 2;
			}
			if(tmp%5==0)
			{
				fcnt++;
				tmp /= 2;
			}
			else break;
		}
	}
	cout<<min(tcnt, fcnt);
	return 0;
}