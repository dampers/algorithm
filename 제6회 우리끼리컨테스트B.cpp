#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
char pass[13] = {'#', '*', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool check[14];
char word[5];
void f(int pos)
{
	if(pos==4)
	{
		printf("%s\n", word);
		return ;
	}
	for(int i=0;i<12;i++)
	{
		if(word[pos]=='\0')
		{
			word[pos] = pass[i];
			f(pos+1);
			word[pos] = '\0';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	f(0);
	return 0;
}
