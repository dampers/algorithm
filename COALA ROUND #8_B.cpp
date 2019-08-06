#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
int abc[4];
char ans[5];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<3;i++)
	{
		scanf(" %s", ans);
		if(ans[1]=='>') abc[(int)ans[0]-'A']++;
		else if(ans[1]=='<') abc[(int)ans[2]-'A']++;
	}
	vector<char> v;
	for(int i=0;i<3;i++)
	{
		char tmp = 'A';
		for(int j=0;j<3;j++)
		{
			if(abc[j]==i)
			{
				v.push_back(tmp+j);
				break;
			}
		}
	}
	int size = v.size();
	if(size==3)
	{
		printf("%c%c%c",v[0],v[1],v[2]);
	}
	else
		printf("Impossible");
	return 0;
}