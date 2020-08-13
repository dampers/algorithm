#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, goal;
	cin>>s>>goal;
	while(s.length()<goal.length())
	{
		if(goal.back()=='B')
		{
			goal.pop_back();
			reverse(goal.begin(), goal.end());
		}
		else goal.pop_back();
	}
	if(s==goal) cout<<1;
	else cout<<0;
	return 0;
}