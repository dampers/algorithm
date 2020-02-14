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
	int n;
	cin>>n;
	deque<int> deq;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int tmp;
		if(s=="push_back")
		{
			cin>>tmp;
			deq.push_back(tmp);
		}
		else if(s=="push_front")
		{
			cin>>tmp;
			deq.push_front(tmp);
		}
		else if(s=="front")
		{
			if(deq.empty()) cout<<-1<<endl;
			else cout<<deq.front()<<endl;
		}
		else if(s=="back")
		{
			if(deq.empty()) cout<<-1<<endl;
			else cout<<deq.back()<<endl;
		}
		else if(s=="pop_front")
		{
			if(deq.empty()) cout<<-1<<endl;
			else
			{
				cout<<deq.front()<<endl;
				deq.pop_front();
			}
		}
		else if(s=="pop_back")
		{
			if(deq.empty()) cout<<-1<<endl;
			else
			{
				cout<<deq.back()<<endl;
				deq.pop_back();
			}
		}
		else if(s=="size") cout<<deq.size()<<endl;
		else if(s=="empty")
		{
			if(deq.empty()) cout<<1<<endl;
			else cout<<0<<endl;
		}

	}
	return 0;
}