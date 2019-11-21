#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool num[101];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<=100;i++)
		for(int j=i;j<=100;j+=i)
			if(num[j]) num[j] = false;
			else num[j] = true;
	int q;
	cin>>q;
	while(q--)
	{
		int n, cnt = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
			if(num[i]) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}