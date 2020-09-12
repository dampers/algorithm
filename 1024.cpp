#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

vector<lld> sum;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin>>n>>l;
	for(int i=l;i<=100;i++)
	{
		int k = i*(i-1)/2;
		if((n-k)%i==0 && (n-k)/i>=0)
		{
			for(int j=0;j<i;j++)
				cout<<(n-k)/i+j<<' ';
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
