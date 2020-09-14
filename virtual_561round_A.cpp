#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

lld alp[26];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		alp[v[i][0]-'a']++;
	}
	lld sum = 0LL;
	for(int i=0;i<26;i++)
	{
		if(alp[i]>2)
		{
			lld tmpa = alp[i]/2, tmpb = alp[i]/2;
			if(alp[i]%2) tmpa++;
			sum += (tmpa*(tmpa-1))/2 + (tmpb*(tmpb-1))/2;
		}
	}
	cout<<sum;


	return 0;
}