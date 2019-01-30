#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<string,int> > a, pair<int,pair<string,int> > b)
{
	if(a.first==b.first) return a.second.second<b.second.second;
	return a.first<b.first;
	
}


int main()
{
	int n;
	
	scanf("%d", &n);
	vector<pair<int,pair<string,int> > > v;
	for(int i=0;i<n;i++)
	{
		int a;
		string b;
		cin >> a >>b;
		v.push_back({a,{b,i}});
	}
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<n;i++)
	{
		cout << v[i].first << " " << v[i].second.first<<"\n";
	}
	
	return 0;
}