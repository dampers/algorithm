#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int num[1000000];

bool comp(int &a, int &b)
{
	return a>b;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num, num+n, comp);
	for(int i=0;i<n;i++)
		cout<<num[i]<<endl;
	return 0;
}