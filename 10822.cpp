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
	getline(cin, s);
	int len = s.length();
	lld sum = 0, cnt = 0;
	for(int i=len-1;i>=0;i--)
	{
		if(s[i]!=',') sum += pow(10, cnt)*((lld)s[i]-'0');
		else cnt = -1;
		cnt++;
	}
	cout<<sum;
	return 0;
}