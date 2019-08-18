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
	cin>>n;
	set<int> s;
	int tmp;
	for(int i=0;i<n;i++)
	{	
		cin>>tmp;
		s.insert(tmp);
	}
	for(set<int>::iterator i=s.begin();i!=s.end();i++)
		cout<<*i<<'\n';
	return 0;
}