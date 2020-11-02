#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int gcd(int a, int b)
{
	while(b)
	{
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		vector<int> v;
		int rg = 4*n;
		v.push_back(rg);
		for(int i=rg-1;i>=1;i--)
		{
			bool flag = false;
			for(int j=0;j<v.size();j++)
			{
				if(gcd(v[j], i)==1 || v[j]%i==0)
				{
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				v.push_back(i);
			}
			if(v.size()==n)
			{
				break;
			}
		}
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<' ';
		cout<<endl;
	}
	return 0;
}