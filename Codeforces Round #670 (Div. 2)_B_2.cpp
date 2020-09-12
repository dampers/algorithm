
#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;
 
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
		vector<lld> num;
		for(int i=0;i<n;i++)
		{
			lld tmp;
			cin>>tmp;
			num.push_back(tmp);
		}
		sort(num.begin(), num.end());
		vector<lld> bf, ef;
		lld mx = 1LL;
		for(int i=0;i<5;i++)
		{
			mx *= num[i];
			bf.push_back(mx);
		}
		lld kmx = 1LL;
		for(int i=n-1;i>=n-5;i--)
		{
			kmx *= num[i];
			ef.push_back(kmx);
		}
		mx = max(mx, kmx);
		for(int i=0;i<4;i++)
		{
			mx = max(mx, bf[i]*ef[3-i]);
			mx = max(mx, bf[3-i]*ef[i]);

		}
		cout<<mx<<endl;
	}
	return 0;
}