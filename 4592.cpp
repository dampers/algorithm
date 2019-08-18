#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int check[30];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, tmp;
	while(1)
	{
		cin>>n;
		if(!n) return 0;
		for(int i=0;i<n;i++)
			cin>>check[i];
		tmp = check[0];
		cout<<tmp<<' ';
		for(int i=1;i<n;i++)
		{
			if(tmp!=check[i])
			{
				tmp = check[i];
				cout<<tmp<<' ';
			}
		}
		cout<<"$\n";
	}
	return 0;
}