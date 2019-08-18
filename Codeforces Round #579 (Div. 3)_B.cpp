#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
int num[404];
int check[10005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	vector<int> v;
	while(tc--)
	{
		memset(check, 0, sizeof(check));
		int n;
		cin>>n;
		for(int i=0;i<4*n;i++)
		{
			cin>>num[i];
			check[num[i]]++;
		}
		bool flag = false;
		for(int i=1;i<10004;i++)
		{
			if(check[i]%2)
			{
				flag = true;
				break;
			}
			if(check[i]) v.push_back(i);
		}
		if(flag)
		{
			cout<<"NO\n";
			v.clear();
			continue;
		}
		int size = v.size();
		if(size==1)
		{
			if(check[v[0]]%4==0) cout<<"YES\n";
			else cout<<"NO\n";
			v.clear();
			continue;
		}
		int sq = v[0]*v[size-1];
		for(int i=0;i<size/2;i++)
		{
			//printf("v[i] = %d v[size-i-1] = %d check[vi] = %d check[size-i-1] = %d\n", v[i], v[size-i-1], check[v[i]], check[v[size-i-1]]);
			if(sq!=v[i]*v[size-i-1] || check[v[i]]!=check[v[size-i-1]])
			{
				flag = true;
				break;
			}
		}
		if(size%2 && sq!=v[size/2]*v[size/2] && check[v[size/2]]%4==0)
		{
			flag = true;
		}
		if(flag)
		{
			cout<<"NO\n";
			v.clear();
			continue;
		}
		else
		{
			cout<<"YES\n";
			v.clear();
			continue;
		}

	}
	return 0;
}