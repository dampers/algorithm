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
		int n, k;
		cin>>n>>k;
		list<int> alist;
		for(int i=0;i<n;i++)
			alist.push_back(i+1);
		list<int>::iterator it = alist.begin();
		int next = 0;
		while(alist.size()>2)
		{
			alist.erase(it);
			next = (next+k-1)%alist.size();
			it = alist.begin();
			for(int i=0;i<next;i++)
			{
				it++;
				if(it==alist.end()) it = alist.begin();
			}
		}
		for(auto s : alist)
			cout<<s<<' ';
		cout<<endl;
	}
	return 0;
}