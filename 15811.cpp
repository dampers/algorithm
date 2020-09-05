#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

map<char, int> mp;
vector<string> v(3);
bool check[11];
int number[11];
int numbering = 1;
bool flag = false;

bool yes()
{
	vector<lld> num(3, 0LL);
	for(int i=0;i<3;i++)
	{
		lld ten = 1LL;
		for(int j=v[i].length()-1;j>=0;j--)
		{
			num[i] += number[mp[v[i][j]]]*ten;
			ten *= 10;
		}
	}
	if(num[0]+num[1]==num[2]) return true;
	return false;
}

void f(int pos)
{
	if(pos==numbering)
	{
		if(yes()) flag = true;
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(!check[i])
		{
			check[i] = true;
			number[pos] = i;
			f(pos+1);
			if(flag) return;
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<3;i++)
	{
		cin>>v[i];
		for(int j=0;j<v[i].length();j++)
			if(mp[v[i][j]]==0) mp[v[i][j]] = numbering++;
	}
	flag = false;
	f(1);
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}