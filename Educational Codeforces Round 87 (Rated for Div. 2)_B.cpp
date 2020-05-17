#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[4];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		int mn = s.length(), cnt = 0, k = 0;
		bool flag = false;
		int ccnt = 0;
		memset(check, false, sizeof(check));
		for(int i=0;i<(int)s.length();i++)
		{
			int tmp = s[i]-'0';
			if(check[tmp]==false && k!=tmp)
			{
				//cout<<"A"<<endl;
				cnt++;
				check[tmp] = true;
				ccnt++;
				if(ccnt==2)
				{
					cnt = 2;
				}
				k = tmp;
			}
			else if(check[tmp]==true && k!=tmp)
			{
				//cout<<"B"<<endl;
				cnt = 2;
				ccnt = 2;
				k = tmp;
			}
			else if(check[tmp]==true && k==tmp)
			{
				//cout<<"C"<<endl;
				if(ccnt==1) cnt = 1;
				else cnt++;
			}
			if(ccnt==3)
			{
				//cout<<"D"<<endl;
				mn = min(mn, cnt);
				memset(check, false, sizeof(check));
				check[tmp] = true;
				check[s[i-1]-'0'] = true;
				ccnt = 2;
				cnt = 2;
				k = tmp;
				flag = true;
			}
			//cout<<cnt<<' '<<ccnt<<endl;
		}
		if(!flag) cout<<0<<endl;
		else cout<<mn<<endl;
	}
	
	return 0;
}