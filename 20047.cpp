#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n, l, r;

bool dp(string& a, string& b, int pos, int n, int check, int aindex)
{
	if(pos==n) return true;
	bool ret = false;
	if(aindex==l || aindex==r) aindex++;
	if(aindex<n && b[pos]==a[aindex])
		ret |= dp(a, b, pos+1, n, check, aindex+1);
	if(check==0 && b[pos]==a[l])
		ret |= dp(a, b, pos+1, n, 1, aindex);
	if(check==1 && b[pos]==a[r])
		ret |= dp(a, b, pos+1, n, 2, aindex);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	string a, b;
	cin>>a>>b;
	cin>>l>>r;
	if(dp(a, b, 0, n, 0, 0)) cout<<"YES";
	else cout<<"NO";
	return 0;
}
