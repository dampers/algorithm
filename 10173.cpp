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
	string s;
	string eoi("EOI");
	while(1)
	{
		bool flag = false;
		getline(cin, s);
		int len = s.length();
		if(!s.compare(eoi)) return 0;
		if(len<4)
		{
			cout<<"Missing\n";
			continue;
		}
		for(int i=0;i<len-3;i++)
		{
			if((s[i]=='N'||s[i]=='n')&&(s[i+1]=='E'||s[i+1]=='e')&&(s[i+2]=='M'||s[i+2]=='m')&&(s[i+3]=='O'||s[i+3]=='o'))
			{
				flag = true;
				break;
			}
		}
		if(flag) cout<<"Found\n";
		else cout<<"Missing\n";
	}
	return 0;
}