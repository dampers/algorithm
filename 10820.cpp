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
	while(getline(cin, s))
	{
		int m = 0, d = 0, n = 0, p = 0;
		int len = s.length();
		for(int i=0;i<len;i++)
		{
			if(s[i]>='A' && s[i]<='Z') d++;
			else if(s[i]>='a' && s[i]<='z') m++;
			else if(s[i]>='0' && s[i]<='9') n++;
			else if(s[i]==' ')p++;
		}
		printf("%d %d %d %d\n", m, d, n, p);
	}
	return 0;
}