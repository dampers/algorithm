#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

int numa[9];
int numb[9];

int main()
{
	for(int i=0;i<8;i++) scanf("%1d", &numa[i]);
	for(int i=0;i<8;i++) scanf("%1d", &numb[i]);
	queue<int> q;
	for(int i=0;i<8;i++)
	{
		q.push(numa[i]);
		q.push(numb[i]);
	}
	int size = q.size();
	while(size>2)
	{
		//printf("%d\n", size);
		for(int i=0;i<size-1;i++)
		{
			int k;
			k = q.front();
			q.pop();
			q.push((k+q.front())%10);
		}
		q.pop();
		size = q.size();
	}
	for(int i=0;i<2;i++)
	{
		printf("%d", q.front());
		q.pop();
	}
	return 0;
}