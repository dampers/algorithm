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
	string s;
	getline(cin, s);
	vector<char> type[202];
	int ind = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ' && ind==0) ind++;
		else if(s[i]==',' && i+1<s.length() && s[i+1]==' ')
		{
			ind++;
			i+=2;
		}
		type[ind].push_back(s[i]);
	}
	for(int i=1;i<=ind;i++)
	{
		string var, t;
		for(int j=0;j<(int)type[0].size();j++)
			cout<<type[0][j];
		//sort(type[i].begin(), type[i].end());
		bool flag = false;
		reverse(type[i].begin(), type[i].end());
		for(int j=0;j<(int)type[i].size();j++)
		{
			if(type[i][j]==';' || type[i][j]==' ') continue;
			else if(type[i][j]=='*'||type[i][j]=='&')
				t += type[i][j];
			else if(type[i][j]=='[') t += ']';
			else if(type[i][j]==']') t += '[';
			else var += type[i][j];
		}
		reverse(var.begin(), var.end());
		cout<<t<<' '<<var<<';'<<endl;
	}
	return 0;
}