#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int sum = INT_MAX;

void choice(int n, int pos, vector<vector<int>>& v, vector<bool>& check, int k)
{
	if(pos==n/2)
	{
		int asum = 0, bsum = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;
				if(check[i]==check[j])
				{
					if(check[i]) asum += v[i][j];
					else bsum += v[i][j];
				}
			}
		}
		sum = min(sum, abs(asum-bsum));
		return ;
	}
	for(int i=k;i<n;i++)
	{
		if(!check[i])
		{
			check[i] = true;
			choice(n, pos+1, v, check, i+1);
			check[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<vector<int>> v(n, vector<int> (n, 0));
	vector<bool> check(n, false);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>v[i][j];

	choice(n, 0, v, check, 0);
	cout<<sum;
	

	return 0;
}