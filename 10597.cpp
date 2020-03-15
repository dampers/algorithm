#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

vector<int> v;
string s;
int kcnt;
bool check[55], flag;

void f(int pos, int k)
{
	if(pos==kcnt)
	{
		flag = true;
		return;
	}
	int oc = (int)(s[k]-'0'), tc = oc*10+(s[k+1]-'0');
	if(!check[oc] && oc<=kcnt && oc>0)
	{
		check[oc] = true;
		v.push_back(oc);
		f(pos+1, k+1);
		if(flag) return;
		v.pop_back();
		check[oc] = false;
	}
	if(!check[tc] && tc<=kcnt && tc>0)
	{
		check[tc] = true;
		v.push_back(tc);
		f(pos+1, k+2);
		if(flag) return;
		v.pop_back();
		check[tc] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	kcnt = s.length();
	if(kcnt>9) kcnt = (kcnt-9)/2+9;
	f(0, 0);
	int size = v.size();
	for(int i=0;i<size;i++)
		cout<<v[i]<<' ';
	return 0;
}