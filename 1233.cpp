#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[81];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
				num[i+j+k]++;
	int ind = 0;
	for(int i=1;i<=a+b+c;i++)
		if(num[ind]<num[i]) ind = i;
	cout<<ind;
	return 0;
}