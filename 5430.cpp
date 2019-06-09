#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;

char ord[100001];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	scanf("%d", &t);
	vector <int> v;
	for(int z=0;z<t;z++)
	{
		int cnt = 0;
		scanf(" %s %d", ord, &cnt);
		//printf("%s\n%d\n", ord, cnt);

		int ncnt = cnt;
		int tmp;
		for(int i=0;i<ncnt;i++)
		{
			scanf(" %d", &tmp);
			v.push_back(tmp);
		}
		reverse(v.begin(), v.end());
		int size = strlen(ord);
		bool flag = false;
		int fpoint = 0;
		for(int i=0;i<size;i++)
		{
			if(ord[i]=='D')
			{
				if(cnt==0)
				{
					flag = true;
					break;
				}
				else
				{
					cnt--;
					v.pop_back();
				}
			}
			else if(ord[i]=='R')
			{
				reverse(v.begin(), v.end());
			}
		}
		if(flag) cout<<"error"<<endl;
		else
		{
			cout<<'[';
			int vsize = v.size();
			for(int i=0;i<vsize-1;i++)
					cout<<v[i]<<',';
			cout<<v[vsize-1]<<']'<<endl;
		}
		v.clear();
	}
	return 0;
}