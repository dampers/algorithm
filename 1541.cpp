#include <bits/stdc++.h>
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
using namespace std;
typedef long long lld;

char a[55];

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf(" %s", a);
	int len = strlen(a);
	vector<int> num;
	vector<char> oper;
	bool kflag = false;
	for(int i=0;i<len;i++)
	{
		if(kflag) break;
		if(a[i]=='+') oper.push_back('+');
		else if(a[i]=='-') oper.push_back('-');
		else
		{
			int tmp = 0;
			for(int j=i;j<i+5&&j<len;j++)
			{
				if(a[j]>='0'&&a[j]<='9')
				{
					tmp += a[j]-'0';
					tmp *= 10;
					if(j==len-1)
					{
						tmp /= 10;
						kflag = true;
						break;
					}
				}
				else
				{
					tmp /= 10;
					i = j-1;
					break;
				}
			}
			num.push_back(tmp);
		}
	}
	int sum = num[0], numsize = num.size(), opsize = oper.size(), op1 = 1, op2 = 0, tmp = 0;
	bool flag = false;
	/*for(int i=0;i<numsize;i++)
		printf("%d ", num[i]);*/
	while(op1<numsize && op2<opsize)
	{
		//printf("sum = %d\n", sum);
		//printf("tmp = %d\n", tmp);
		if(oper[op2]=='+')
		{
			if(flag) tmp += num[op1++];
			else sum += num[op1++];
		}
		else if(oper[op2]=='-')
		{
			if(flag)
			{
				if(op1+1<numsize && num[op1]<num[op1+1] && op2+1<opsize && oper[op2+1]=='+')
				{
					tmp -= num[op1++];
					continue;
				}
				flag = false;
				sum -= tmp;
				tmp = 0;
			}
			else
			{
				if(op2+1<opsize && oper[op2+1]=='-')
				{
					sum -= num[op1++];
					continue;
				}
				flag = true;
				tmp = num[op1++];
			}
		}
		printf("%d\n", sum);
	}
	printf("%d", sum);
	return 0;
}