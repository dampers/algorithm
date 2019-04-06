#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int num[2001];
vector<int> numo;
vector<int> nume;
int main()
{
	int n;
	scanf(" %d", &n);
	int ocnt = 0, ecnt = 0;
	for(int i=0;i<n;i++)
	{
		scanf(" %d", &num[i]);
		if(num[i]%2)
		{
			ocnt++;
			numo.push_back(num[i]);
		}
		else
		{
			ecnt++;
			nume.push_back(num[i]);
		}
	}
	sort(num, num+n);
	sort(numo.begin(), numo.end());
	sort(nume.begin(), nume.end());
	if(abs(ocnt-ecnt)<=1)
	{
		printf("0");
		return 0;
	}
	if(ocnt==0)
	{
		int sum = 0;
		for(int i=0;i<n-1;i++)
			sum += num[i];
		printf("%d", sum);
		return 0;
	}
	else if(ecnt==0)
	{
		int sum = 0;
		for(int i=0;i<n-1;i++)
			sum += num[i];
		printf("%d", sum);
		return 0;
	}
	if(ocnt>ecnt)
	{
		for(int i=0;i<ecnt+1;i++)
		{
			numo.pop_back();
		}
		int sum = 0, size = (int)numo.size();
		for(int i=0;i<size;i++)
		{
			sum += numo[i];
		}
		printf("%d", sum);
	}
	else if(ecnt>ocnt)
	{
		for(int i=0;i<ocnt+1;i++)
		{
			nume.pop_back();
		}
		int sum = 0, size = (int)nume.size();
		for(int i=0;i<size;i++)
		{
			sum += nume[i];
		}
		printf("%d", sum);
	}
	return 0;
}