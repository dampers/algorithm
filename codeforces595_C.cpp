#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[40];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	vector<lld> v;
	lld tmp = 1LL;
	for(int i=0;i<39;i++)
	{
		v.push_back(tmp);
		tmp *= 3;
	}
	//reverse(v.begin(), v.end());
	int size = v.size();
	while(q--)
	{
		memset(check, false, sizeof(check));
		lld n;
		cin>>n;
		tmp = n;
		int ssize = size;
		bool flag = false;
		while(--ssize>=0)
		{
			if(v[ssize]<=tmp)
			{
				tmp -= v[ssize];
				check[ssize] = true;
				if(v[ssize]<=tmp)
					flag = true;
			}
		}
		if(!flag)
		{
			cout<<n<<endl;
			continue;
		}
		for(int i=0;i<39;i++)
		{
			if(!check[i])
			{
				check[i] = true;
				for(int j=i-1;j>=0;j--)
					check[j] = false;
				break;
			}
		}
		n = 0;
		for(int i=0;i<size;i++)
		{
			if(check[i] == true)
				n += v[i];
			//cout<<n<<endl;
		}
		cout<<n<<endl;
	}
	
	return 0;
}