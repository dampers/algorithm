#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int rsize = 0, bsize = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') rsize++;
		else bsize++;
	}
	int rfcnt = 0, rbcnt = 0;
	int bfcnt = 0, bbcnt = 0;
	for(int i=0;i<rsize;i++)
		if(s[i]=='R') rfcnt++;
		else break;
	for(int i=n-1;i>=n-rsize;i--)
		if(s[i]=='R') rbcnt++;
		else break;
	for(int i=0;i<bsize;i++)
		if(s[i]=='B') bfcnt++;
		else break;
	for(int i=n-1;i>=n-bsize;i--)
		if(s[i]=='B') bbcnt++;
		else break;
	//cout<<rsize-rfcnt<<' '<<rsize-rbcnt<<endl;
	//cout<<bsize-bfcnt<<' '<<bsize-bbcnt<<endl;
	cout<<min({rsize-rfcnt, rsize-rbcnt, bsize-bfcnt, bsize-bbcnt});


	return 0;
}