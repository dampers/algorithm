#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[21];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<21;i++) num[i] = i;
	for(int i=0;i<10;i++)
	{
		int a, b;
		cin>>a>>b;
		reverse(num+a, num+b+1);
	}
	for(int i=1;i<21;i++) cout<<num[i]<<' ';
	return 0;
}