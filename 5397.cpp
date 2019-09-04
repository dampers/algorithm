#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;
char s[1000005];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	scanf(" %d", &n);
	vector<char> v, tmp;
	while(n--)
	{
		scanf(" %s", s);
		int len = strlen(s), k = 0;
		for(int i=0;i<len;i++)
		{
			int size = v.size();
			if(s[i]=='<')
			{
				k--;
				if(k<0) k = 0;
			}
			else if(s[i]=='>')
			{
				k++;
				if(k>size-1) k = size-1;
			}
			else if(s[i]=='-')
			{
			
			}
		}
	}
	return 0;
}