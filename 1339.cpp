#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
typedef long long lld;

int n;
string num[11];
int number[11];
int numbering = 1;
bool check[11];
map<char, int> mp;
lld mx;

lld find()
{
	lld sum = 0LL, ten = 1LL;
	for(int i=0;i<n;i++)
	{
		ten = 1LL;
		for(int j=num[i].length()-1;j>=0;j--)
		{
			sum += number[mp[num[i][j]]]*ten;
			ten *= 10;
		}
	}
	return sum;
}

void f(int pos)
{
	if(pos==numbering)
	{
		mx = max(mx, find());
		return;
	}
	for(int i=9;i>=0;i--)
	{
		if(!check[i])
		{
			check[i] = true;
			number[pos] = i;
			f(pos+1);
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	time_t start, end;
	start = clock();
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		for(int j=0;j<num[i].length();j++)
		{
			if(mp[num[i][j]]==0)
			{
				mp[num[i][j]] = numbering++;
			}
		}
	}
	f(1);
	cout<<mx<<endl;
	end = clock();
	cout<<(double)(end-start)/1000;
	return 0;
}