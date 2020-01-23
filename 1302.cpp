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
	map<string, int> book;
	int n;
	cin>>n;
	string tmp;
	getline(cin, tmp);
	for(int i=0;i<n;i++)
	{
		getline(cin, tmp);
		if(book[tmp]==0) book[tmp] = 1;
		else book[tmp] = book[tmp]+1;
	}
	int mx = 0;
	string ans = "";
	for(auto it=book.begin();it!=book.end();it++)
	{
		if(mx<it->second)
		{
			mx = it->second;
			ans = it->first;
		}
	}
	cout<<ans;
	return 0;
}