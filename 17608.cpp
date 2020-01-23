#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	int cnt = 1, mx = num[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(mx<num[i])
		{
			cnt++;
			mx = num[i];
		}
	}
	cout<<cnt;
	return 0;
}