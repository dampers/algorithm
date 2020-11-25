#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, k;
		cin>>n>>k;
		string a, b;
		cin>>a>>b;
		vector<int> have(27, 0), need(27, 0);
		for(int i=0;i<n;i++)
		{
			have[a[i]-'a']++;
			need[b[i]-'a']++;
		}
		bool flag = true;
		for(int i=0;i<26;i++)
		{
			if(have[i]<need[i])
			{
				flag = false;
				break;
			}
			have[i] -= need[i];
			if(have[i]%k)
			{
				flag = false;
				break;
			}
			have[i+1] += have[i];
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}