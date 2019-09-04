#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
bool check[44];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<10;i++)
	{
		int tmp;
		cin>>tmp;
		check[tmp%42] = true;
	}
	int cnt = 0;
	for(int i=0;i<42;i++)
		if(check[i]) cnt++;
	cout<<cnt;
	return 0;
}