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
	vector<pair<int, int>> v;
	int n, tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		v.push_back(make_pair(tmp, i+1));
	}
	vector<int> num;
	num.push_back(1);
	int key = abs(v[0].first-1), dir = v[0].first<0?-1:1; // -1 = minus, 1 = plus
	int p = 0;
	v.erase(v.begin());
	int size = v.size();
	for(int i=0;i<size-1;i++)
	{
		int ksize = v.size();
		for(int j=0;j<key;j++)
		{
			p += dir;
			if(p==ksize) p = 0;
			if(p<0) p = ksize-1;
		}
		num.push_back(v[p].second);
		key = abs(v[p].first);
		dir = v[p].first<0?-1:1;
		v.erase(v.begin()+p);
	}
	num.push_back(v[0].second);
	for(int i=0;i<n;i++)
		cout<<num[i]<<' ';
	return 0;
}