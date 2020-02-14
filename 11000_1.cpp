#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

comp(pair<lld, lld> &a, pair<lld, lld> &b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<lld, lld> > parray;
	for(int i=0;i<n;i++)
		cin>>parray[i].first>>parray[i].second;
	sort(parray., parray+n, comp);
	for(int i=0;i<n;i++)
		cout<<parray[i].first<<' '<<parray[i].second<<endl;
	return 0;
}