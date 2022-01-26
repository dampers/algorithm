#include <bits/stdc++.h>
 
using namespace std;
 
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
#define int long long
 
using pii = pair<int, int>;
 
const double EPS = 1e-9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool comp(string& a, string& b)
{
	if(a.length() != b.length()) return a.length() < b.length();
	for(size_t i=0;i<a.length();i++)
	{
		if(a[i] > b[i]) return false;
		else if(a[i] < b[i]) return true;
	}
	return true;

}
 
int32_t main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<string> v;
	string tmp;
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		string nums = "";
		bool flag = false;
		for(auto &K : tmp)
		{
			if(!flag && K >= '0' && K <= '9')
			{
				flag = true;
				nums.push_back(K);
			}
			else if(flag && K >= '0' && K <= '9')
				nums.push_back(K);
			else if(flag && K >='a' && K <= 'z')
			{
				flag = false;
				v.push_back(nums);
				nums = "";
			}
		}
		if(flag) v.push_back(nums);
	}
	for(auto &S : v)
	{
		reverse(S.begin(), S.end());
		while(S.back() == '0' && S.length() > 1)
			S.pop_back();
		reverse(S.begin(), S.end());
	}
	sort(v.begin(), v.end(), comp);
	for(auto &K : v)
		cout << K << endl;

	return 0;
}