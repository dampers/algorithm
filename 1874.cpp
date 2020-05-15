#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check[100005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> res(n), st;
	vector<char> v;
	for(int i=0;i<n;i++)
	{
		cin>>res[i];
	}
	int resp = 0, stk = 1;
	bool res_flag = false;
	while(resp<n)
	{
		if(stk<res[resp])
		{
			v.push_back('+');
			check[stk] = true;
			st.push_back(stk++);
		}
		else if(stk==res[resp])
		{
			if(!check[stk])
			{
				v.push_back('+');
				stk++;
			}
			v.push_back('-');
			resp++;
		}
		else if(!st.empty() && st.back()==res[resp])
		{
			v.push_back('-');
			st.pop_back();
			resp++;
		}
		else
		{
			res_flag = true;
			break;
		}
	}
	if(res_flag) cout<<"NO";
	else
	{
		for(int i=0;i<(int)v.size();i++)
			cout<<v[i]<<endl;
	}
	return 0;
}