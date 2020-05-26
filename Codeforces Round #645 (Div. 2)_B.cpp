#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[200005];

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
		for(int i=0;i<n;i++)
			cin>>num[i];
		sort(num, num+n);
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			if(num[i]<=i+1) sum = i+1;
		}
		cout<<sum+1<<endl;
	}
	
	return 0;
}