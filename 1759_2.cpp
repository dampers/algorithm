#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

bool check_moum(int k, vector<char>& alp)
{
	if(alp[k]=='a') return true;
	if(alp[k]=='e') return true;
	if(alp[k]=='i') return true;
	if(alp[k]=='o') return true;
	if(alp[k]=='u') return true;
	return false;
}
int l, c;

void rec(int pos, int num, vector<char>& alp, vector<char>& ans,
		vector<bool>& check, int m, int j)
{
	if(pos == l)
	{
		if(m >= 1 && j >= 2)
		{
			for(int i=0;i<l;i++)
				cout<<ans[i];
			cout<<endl;
		}
		return;
	}

	for(int i=num;i<c;i++)
	{
		if(!check[i])
		{
			if(check_moum(i, alp)) m++;
			else j++;
			check[i] = true;
			ans[pos] = alp[i];
			rec(pos+1, i, alp, ans, check, m, j);
			check[i] = false;
			if(check_moum(i, alp)) m--;
			else j--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> l >> c;
	vector<char> alp(c, '\0'), ans(c, '\0');
	vector<bool> check(c, false);

	for(int i=0;i<c;i++)
		cin>>alp[i];
	sort(alp.begin(), alp.end());
	rec(0, 0, alp, ans, check, 0, 0);

	return 0;
}