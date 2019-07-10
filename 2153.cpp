#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
using namespace std;
typedef long long lld;
bool pm[100005];
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	pm[1] = false;
	for(int i=2;i*i<100001;i++)
	{
		if(pm[i]==true) continue;
		for(int j=i+i;j<100001;j+=i)
			pm[j] = true;
	}
	string a;
	getline(cin, a);
	int len = a.length();
	int prime = 0;
	for(int i=0;i<len;i++)
	{
		if(a[i]>='a' && a[i]<='z')
			prime += a[i]-'a'+1;
		else if(a[i]>='A' && a[i]<='Z')
			prime += a[i]-'A'+27;
	}
	//cout<<"prime = "<<prime<<endl;
	if(pm[prime]==true) cout<<"It is not a prime word.";
	else cout<<"It is a prime word.";
	return 0;
}
