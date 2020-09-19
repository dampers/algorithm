#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<int> st;
	int n;
	cin>>n;
	for(int i=0, tmp;i<n;i++)
	{
		cin>>tmp;
		st.insert(tmp);
	}
	for(set<int>::iterator it=st.begin();it!=st.end();it++)
		cout<<*it<<' ';
	return 0;
}