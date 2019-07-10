#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	vector <char> line;
	while(1)
	{
		getline(cin, a);
		if(a[0]=='.')
			return 0;
		int len = a.length();
		bool flag = false;
		for(int i=0;i<len;i++)
		{
			if(a[i]=='[')
			line.push_back(a[i]);
			else if(a[i]=='(')
			line.push_back(a[i]);
			else if(a[i]==')')
			{
				if(line.empty())
				{
					flag = true;
					break;
				}
				else if(line.back()=='(')
					line.pop_back();
				else
				{
					flag = true;
					break;
				}
			}
			else if(a[i]==']')
			{
				if(line.empty())
				{
					flag = true;
					break;
				}
				else if(line.back()=='[')
					line.pop_back();
				else
				{
					flag = true;
					break;
				}
			}

		}
		if(line.empty() && !flag)
			cout<<"yes\n";
		else
			cout<<"no\n";
		line.clear();
	}
	return 0;
}