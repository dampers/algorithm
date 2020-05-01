#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int num[105], sum[105];
int check[105];

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
		int sk = 0;
		map<int, int> mp;
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
			sum[i] = sum[i-1]+num[i];
			if(mp[num[i]]==0)
			{
				v.push_back(num[i]);
				mp[num[i]] = 1;
				sk = i;
			}
			else mp[num[i]]++;
		}
		vector<int> res;
		if((int)mp.size()>k)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(n==k)
		{
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
				cout<<num[i]<<' ';
			cout<<endl;
			continue;
		}
		else if(k==(int)v.size())
		{
			int size = v.size(), ind = 0;
			for(int i=1;i<=n;i++)
			{
				if(v[ind]==num[i])
				{
					res.push_back(num[i]);
					ind = (ind+1)%size;
				}
				else
				{
					while(v[ind]!=num[i])
					{
						res.push_back(v[ind]);
						ind = (ind+1)%size;
					}
					res.push_back(num[i]);
					ind = (ind+1)%size;
				}
			}
			int rsize = res.size();
			cout<<rsize<<endl;
			for(int i=0;i<rsize;i++)
				cout<<res[i]<<' ';
			cout<<endl;
		}
		else // k>mp.size()
		{
			for(map<int, int>::iterator it=mp.begin();it!=mp.end();it++)
			{
				if((*it).second==1) continue;
				for(int i=0;i<(*it).second&&(int)v.size()<k;i++)
					v.push_back((*it).first);
			}
			int size = v.size(), ind = 0;
			for(int i=1;i<=n;i++)
			{
				if(v[ind]==num[i])
				{
					res.push_back(num[i]);
					ind = (ind+1)%size;
				}
				else
				{
					while(v[ind]!=num[i])
					{
						res.push_back(v[ind]);
						ind = (ind+1)%size;
					}
					res.push_back(num[i]);
					ind = (ind+1)%size;
				}
			}
			int rsize = res.size();
			cout<<rsize<<endl;
			for(int i=0;i<rsize;i++)
				cout<<res[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}