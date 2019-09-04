#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

struct room
{
	lld s;
	lld e;
	bool check;
};

room num[200005];

bool comp(room &a, room &b)
{
	if(a.e==b.e)
		return a.s<b.s;
	return a.e<b.e;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i].s>>num[i].e;
	sort(num, num+n, comp);
	vector <int> v;
	v.push_back(0);
	for(int i=0;i<n;i++)
	{
		int size = v.size();
		bool flag = false;
		for(int j=0;j<size;j++)
		{
			if(!num[i].check && num[i].s>=v[j])	
			{
				num[i].check = true;
				flag = true;
				v[j] = num[i].e;
				break;
			}
			else continue;
		}
		if(!flag) v.push_back(num[i].e);
	}
	cout<<v.size();
	return 0;
}