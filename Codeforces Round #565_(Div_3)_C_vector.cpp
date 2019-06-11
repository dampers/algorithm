	#include <bits/stdc++.h>
	#define swap(a,b) (a)^=(b)^=(a)^=(b)
	using namespace std;
	typedef long long lld;
	int qur[] = {4, 8, 15 ,16, 23 ,42};
	int main()
	{
		ios_base::sync_with_stdio(NULL);
		cin.tie(NULL);
		cout.tie(NULL);
		int n;
		cin>>n;
		vector<vector<int>> v(6, vector<int>(0, 0));;
		int tmp;
		int cnt = 0, mn = 987654321;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			for(int j=0;j<6;j++)
			{
				if(tmp==qur[j])
				{
					v[j].push_back(i);
					break;
				}
			}
		}
		for(int i=0;i<6;i++)
		{
			if(mn>v[i].size()) mn = v[i].size();
			reverse(v[i].begin(), v[i].end());
		}
		int size, ccnt;
		for(int i=0;i<mn;i++)
		{
			ccnt = 1;
			tmp = v[0].back();
			v[0].pop_back();
			for(int j=1;j<6;j++)
			{
				size = v[j].size();
				for(int k=0;k<size;k++)
				{
					if(tmp<v[j].back())
					{
						ccnt++;
						tmp = v[j].back();
						v[j].pop_back();
						break;
					}
					else
						v[j].pop_back();
				}
			}
			if(ccnt == 6) n-=6;
			else break;
		}
		printf("%d", n);
		return 0;
	}