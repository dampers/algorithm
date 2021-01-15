#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin>>tc;
	while(tc--)
	{
		int streng, intel, exper;
		cin>>streng>>intel>>exper;
		if(exper==0)
		{
			if(streng>intel) cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		}
		else if(streng+exper<=intel)
		{
			cout<<0<<endl;
			continue;
		}
		int left = 0, right = exper;
		while(left<right)
		{
			//cout<<left<<' '<<right<<endl;
			int mid = (left+right)/2;
			if(streng+mid<intel+(exper-mid)) left = mid+1;
			else right = mid;
		}
		while(streng+left<=intel+(exper-left)) left++;
		cout<<exper+1-left<<endl;



	}

	return 0;
}