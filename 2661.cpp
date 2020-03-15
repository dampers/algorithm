#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int n;
string num;
char lst[4] = {'1', '2', '3', '\0'};
bool flag;

bool check()
{
	int len = num.length();
	for(int i=0;i<len;i++)
		for(int j=1;j<=(len-i)/2;j++)
			if(!num.compare(i, j, num, i+j, j)) return false;
	return true;
}

void f(int pos)
{
	if(pos==n)
	{
		flag = true;
		return;
	}
	for(int i=0;i<3;i++)
	{
		num.push_back(lst[i]);
		if(check()) f(pos+1);
		if(flag) return;
		num.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	num = "1";
	f(1);
	cout<<num<<endl;
	return 0;
}