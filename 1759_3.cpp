#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int l, c;

bool check_moum(int k)
{
	if('a'+k == 'a') return true;
	if('a'+k == 'e') return true;
	if('a'+k == 'i') return true;
	if('a'+k == 'o') return true;
	if('a'+k == 'u') return true;
	return false;
}

void rec(int pos, int num, int m, int j, vector<char>& v, vector<int>& check)
{
	if(pos == l)
	{
		if(m >= 1 && j >= 2)
		{
			for(int i=0;i<l;i++)
				cout<<v[i];
			cout<<endl;
		}
		return;
	}
	for(int i=num;i<26;i++)
	{
		if(check[i] == 1)
		{
			if(check_moum(i)) m++;
			else j++;
			check[i] = 2;
			v[pos] = 'a'+i;
			rec(pos+1, i, m, j, v, check);
			check[i] = 1;
			if(check_moum(i)) m--;
			else j--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>l>>c;
	vector<char> v(c, '\0');
	vector<int> check(26, 0);
	for(int i=0;i<c;i++)
	{
		cin>>v[i];
		check[v[i]-'a'] = 1;
	}
	rec(0, 0, 0, 0, v, check);

	return 0;
}