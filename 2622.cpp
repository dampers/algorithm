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
	int k;
	cin>>k;
	int cnt = 0;
	for(int i=1;i<k/2;i++)
		for(int j=i;j<k-i;j++)
		{
			int lk = k-(i+j);
			if(i+j>lk && lk>=i && lk>=j)
			{
				cnt++;
				//cout<<i<<' '<<j<<' '<<k-(i+j)<<endl;;
			}
		}
	cout<<cnt;
	return 0;
}