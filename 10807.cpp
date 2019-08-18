#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[205];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		tmp += 100;
		num[tmp]++;
	}
	cin>>tmp;
	cout<<num[tmp+100];
	return 0;
}