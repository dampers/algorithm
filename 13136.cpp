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
	int sum = 0;
	for(int i=0;i<5;i++)
	{
		int tmp;
		cin>>tmp;
		sum += tmp;
	}
	cout<<sum;
	return 0;
}