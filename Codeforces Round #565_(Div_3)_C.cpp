#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int qur[] = {4, 8, 15, 16, 23, 42};
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int>*a = new queue<int>[6];
	int n, tmp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		for(int j=0;j<6;j++)
		{
			if(qur[j]==tmp)
			{
				a[j].push(i);
				break;
			}
		}
	}
	while(1)
	{
		int cnt = 1;
		bool flag = false;
		if(a[0].empty())
		{
			flag = true;
			break;
		}
		if(flag) break;
		tmp = a[0].front();
		a[0].pop();
		for(int i=1;i<6;i++)
		{
			if(a[i].empty())
			{
				flag = true;
				break;
			}
			while(tmp>a[i].front())
			{
				if(a[i].empty())
				{
					flag = true;
					break;
				}
				a[i].pop();
			}
			if(flag) break;
			tmp = a[i].front();
			cnt++;
			a[i].pop();
		}
		if(cnt==6)
			n -= 6;
	}
	printf("%d", n);
	return 0;
}