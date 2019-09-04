#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int h[100005];

int main()
{
	int n;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf(" %d", &h[i]);
	int mx = 0, top;
	stack<int> st;
	for(int i=0;i<=n;i++)
	{
		while(!st.empty() && h[i] < h[st.top()])
		{
			int bot;
			top = st.top();
			st.pop();
			if(st.empty()) bot = i;
			else bot = i-st.top()-1;
			mx = max(mx, h[top]*bot);
		}
		st.push(i);
	}
	printf("%d", mx);
	return 0;
}