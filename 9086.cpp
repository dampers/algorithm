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
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		cout<<s[0]<<s[s.length()-1]<<endl;
	}
	return 0;
}