#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
string lines;
int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		getline(cin, lines);
		cout<<i<<". "<<lines<<endl;
	}
	return 0;
}