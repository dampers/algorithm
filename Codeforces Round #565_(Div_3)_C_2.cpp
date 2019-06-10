#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
queue<int> q4,q8,q15,q16,q23,q42;
int s[6];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(tmp==4) q4.push(i);
		else if(tmp==8) q8.push(i);
		else if(tmp==15) q15.push(i);
		else if(tmp==16) q16.push(i);
		else if(tmp==23) q23.push(i);
		else if(tmp==42) q42.push(i);
	}
	s[0] = q4.size();
	s[1] = q8.size();
	s[2] = q15.size();
	s[3] = q16.size();
	s[4] = q23.size();
	s[5] = q42.size();
	if(n<6)
	{
		printf("%d", n);
		return 0;
	}
	int mn = 5000000;
	int sum = 0;
	bool flag = false;
	for(int i=0;i<6;i++)
		if(mn>s[i]) mn = s[i];
	while(mn--)
	{
		int cnt = 1;
		if(q4.empty())
		{
			flag = true;
			break;
		}
		tmp = q4.front();
		q4.pop();
		for(int i=0;i<s[1];i++)
		{
			if(q8.empty())
				{
					flag = true;
					break;
				}
			if(tmp<q8.front())
			{
				cnt++;
				tmp = q8.front();
				q8.pop();
				break;
			}
			else
			{
				if(q8.empty())
				{
					flag = true;
					break;
				}
				q8.pop();
			}
		}
		if(flag) break;
		for(int i=0;i<s[2];i++)
		{
			if(q15.empty())
				{
					flag = true;
					break;
				}
			if(tmp<q15.front())
			{
				cnt++;
				tmp = q15.front();
				q15.pop();
				break;
			}
			else
			{
				if(q15.empty())
				{
					flag = true;
					break;
				}
				q15.pop();
			}
		}
		if(flag) break;
		for(int i=0;i<s[3];i++)
		{
			if(q16.empty())
				{
					flag = true;
					break;
				}
			if(tmp<q16.front())
			{
				cnt++;
				tmp = q16.front();
				q16.pop();
				break;
			}
			else
			{
				if(q16.empty())
				{
					flag = true;
					break;
				}
				q16.pop();
			}
		}
		if(flag) break;
		for(int i=0;i<s[4];i++)
		{
			if(q23.empty())
				{
					flag = true;
					break;
				}
			if(tmp<q23.front())
			{
				cnt++;
				tmp = q23.front();
				q23.pop();
				break;
			}
			else
			{
				if(q23.empty())
				{
					flag = true;
					break;
				}
				q23.pop();
			}
		}
		if(flag) break;
		for(int i=0;i<s[5];i++)
		{
			if(q42.empty())
				{
					flag = true;
					break;
				}
			if(tmp<q42.front())
			{
				cnt++;
				tmp = q42.front();
				q42.pop();
				break;
			}
			else
			{
				if(q42.empty())
				{
					flag = true;
					break;
				}
				q42.pop();
			}
		}
		if(flag) break;
		if(cnt==6) n -= 6;
	}
	printf("%d", n);
	return 0;
}