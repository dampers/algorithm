#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int ucpc[4];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	int len = s.length();
	int flag = 0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='U' && flag == 0)
		{
			ucpc[0] = 1;
			flag = 1;
		}
		else if(s[i]=='C' && flag == 1)
		{
			ucpc[1] = 1;
			flag = 2;
		}
		else if(s[i]=='P' && flag == 2)
		{
			ucpc[2] = 1;
			flag = 3;
		}
		else if(s[i]=='C' && flag == 3)
		{
			ucpc[3] = 1;
			flag = 4;
			break;
		}
	}
	if(ucpc[0]*ucpc[1]*ucpc[2]*ucpc[3]) cout<<"I love UCPC";
	else cout<<"I hate UCPC";
	return 0;
}