#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int check(map<char, int>& mp, map<char, int>& goal)
{
	if(mp['A']>=goal['A'] && mp['C']>=goal['C'] && mp['G']>=goal['G'] && mp['T']>=goal['T'])
		return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	map<char, int> mp, goal;
	cin>>goal['A']>>goal['C']>>goal['G']>>goal['T'];
	mp['A'] = mp['C'] = mp['G'] = mp['T'] = 0;
	for(int i=0;i<m;i++)
		mp[s[i]]++;
	int cnt = 0;
	cnt += check(mp, goal);
	for(int i=m;i<n;i++)
	{
		mp[s[i-m]]--;
		mp[s[i]]++;
		cnt += check(mp, goal);
	}
	cout<<cnt;
	return 0;
}