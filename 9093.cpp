#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf("%d\n", &n);
	char tmp = '1';
	int size = 0;
	vector<char> v;
	while(scanf("%c", &tmp)==1)
	{
		if(tmp=='\n' || tmp==' ')
		{
			size = v.size();
			for(int i=0;i<size;i++)
			{
				char ttmp = v.back();
				printf("%c", ttmp);
				v.pop_back();
			}
			printf("%c", tmp);
		}
		else v.push_back(tmp);
	}
	size = v.size();
	for(int i=size-1;i>=0;i--)
	{
		printf("%c", v[i]);
	}


	return 0;
}