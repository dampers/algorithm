#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int num[15];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector <pair<int, int> > v;
	int n, cnt = 0;
	while(scanf(" %d", &n)==1)
	{
		num[cnt] = n;
		cnt++;
	}
	int res = num[cnt-1];
	cnt -= 1;
	sort(num, num+cnt);
	int tmp;
	for(int i=0;i<cnt-1;i++)
	{
		for(int j=i+1;j<cnt;j++)
		{
			tmp = num[i]+num[j];
			if(tmp==res)
			{
				int size = v.size();
				bool flag = true;
				for(int k=0;k<size;k++)
				{
					if(v[k].first==num[i] && v[k].second == num[j])
					{
						flag = false;
						break;
					}
					else if(v[k].first==num[j] && v[k].second == num[i])
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					v.push_back({num[i], num[j]});
					printf("%d %d\n", num[i], num[j]);
				}
			}
		}
	}
	int size = v.size();
	printf("%d", size);
	return 0;
}