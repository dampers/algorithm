#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a;
   
	vector<string> v;
	v.push_back(a);
	string tmp = a;
	int len = a.size();
	for(int i=0;i<len-1;i++)
	{
		reverse(a.begin(), a.end());
		a.pop_back();
		reverse(a.begin(), a.end());
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	return 0;
}