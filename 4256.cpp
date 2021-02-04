#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int n;

int print_post(int pos, int left, int right,
	vector<int>& preo, vector<int>& ino, map<int, int>& idx)
{
	if(pos == n+1 || left > right) return pos;
	if(left == right)
	{
		cout<<ino[left]<<" ";
		return pos+1;
	}

	int parent = idx[preo[pos]], next = print_post(pos+1, left, parent-1, preo, ino, idx);
	int last = print_post(next, parent+1, right, preo, ino, idx);
	cout<<ino[parent]<<" ";
	return last;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		vector<int> preo(n+1, 0), ino(n+1, 0);
		map<int, int> idx;

		for(int i=1;i<=n;i++)
			cin>>preo[i];
		for(int i=1;i<=n;i++)
		{
			cin>>ino[i];
			idx[ino[i]] = i;
		}
		print_post(1, 1, n, preo, ino, idx);
		cout<<endl;
	}
	return 0;
}