#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n;
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		else if(n == 2)
		{
			cout << -1 << endl;
			continue;
		}
		queue<int> q;
		int size = (n*n)/2;
		for(int i=1;i<=size;i++)
		{
			q.push(i);
			q.push(n*n-i+1);
		}
		if(n % 2) q.push(size+1);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i == 0 && j == 0) cout << size+1 << ' ';
				else if(i == n-1 && j == n-1) cout << 1 << ' '; 
				else cout << q.front() << ' ';
				//cout << q.front() << ' ';
				q.pop();
			}
			cout << endl;
		}

	}

	return 0;
}