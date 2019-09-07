#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int cnt;

void f(int n, int k)
{
	if(n==k)
	{
		cnt++;
		return;
	}
	else if(k>n) return;
	f(n, k+1);
	f(n, k+2);
	f(n, k+3);
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		cnt = 0;
		f(n, 0);
		cout<<cnt<<endl;
	}
	return 0;
}