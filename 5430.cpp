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
	deque<int> dq;
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin.ignore();
		getline(cin, s);
		int n, tmp;
		cin>>n;
		cin.ignore(1, '[');
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			dq.push_back(tmp);
			if(i<n-1) cin.ignore(1, ',');
		}
		cin.ignore(1, ']');
		int len = s.length(), flag = 1;
		bool bflag = false;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='R')
			{
				flag *= -1;
			}
			else if(s[i]=='D')
			{
				if(dq.empty())
				{
					bflag = true;
					break;
				}
				if(flag==1) dq.pop_front();
				else dq.pop_back();
			}
		}
		if(bflag) cout<<"error"<<endl;
		else
		{
			int size = dq.size();
			cout<<"[";
			if(flag==1)
			{
				for(int i=0;i<size;i++)
				{
					cout<<dq[i];
					if(i<size-1) cout<<',';
				}
				cout<<"]"<<endl;
			}
			else
			{
				for(int i=size-1;i>=0;i--)
				{
					cout<<dq[i];
					if(i>0) cout<<',';
				}
				cout<<"]"<<endl;
			}
		}
		dq.clear();
	}
	return 0;
}