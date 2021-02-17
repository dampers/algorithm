#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int rec(int pos, int point, vector<int>& ac, vector<int>& answer)
{
	if(pos == 10)
	{
		if(point >= 5) return 1;
		return 0;
	}
	int ret = 0;
	for(int i=1;i<=5;i++)
	{
		if(pos >= 2 && answer[pos-2] == answer[pos-1] && answer[pos-1] == i) continue;
		answer[pos] = i;
		ret += rec(pos+1, point+(answer[pos]==ac[pos]?1:0), ac, answer);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> ac(10, 0), answer(10, 0);
	for(int i=0;i<10;i++)
		cin >> ac[i];
	cout << rec(0, 0, ac, answer);
	return 0;
}