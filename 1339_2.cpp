#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

lld nsum[27];

bool comp(lld a, lld b) {return a>b;}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<string> num(n);
	for(int i=0;i<n;i++)
	{
		lld ten = 1LL;
		cin>>num[i];
		for(int j=num[i].length()-1;j>=0;j--)
		{
			nsum[num[i][j]-'A'] += ten;
			ten *= 10;
		}
	}
	sort(nsum, nsum+27, comp);
	int numbering = 9;
	lld res = 0LL;
	for(int i=0;i<26;i++)
	{
		if(nsum[i]==0) continue;
		res += nsum[i]*numbering;
		numbering--;
	}
	cout<<res;
	return 0;
}