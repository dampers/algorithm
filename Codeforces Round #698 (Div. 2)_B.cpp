#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
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
		int q, d;
		cin>>q>>d;
		vector<int> v(q, 0);
		for(int i=0;i<q;i++)
		{
			cin>>v[i];
			if(v[i] % d == 0 || v[i]%10 == d)
			{
				cout<<"YES"<<endl;
				continue;
			}

			else if(d*10 <= v[i])
			{
				cout<<"YES"<<endl;
				continue;
			}

			int tmp = v[i], cnt = 0;
			bool flag = false;

			for(int j=0;j<10;j++)
			{
				tmp -= d;
				if(tmp%10 == d)
				{
					flag = true;
					break;
				}
			}
	
			if(flag)
			{
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;


		}

	}


	return 0;
}