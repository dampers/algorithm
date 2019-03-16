#include <iostream>
using namespace std;
char flag[51][51];
int main() 
{
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
	    scanf("%s", flag[i]);
	}
	int mn=2000000000, cnt;
	int wcnt, bcnt, rcnt;
	for(int i=0;i<n-2;i++)
	{
		wcnt=0;
	    for(int v=0;v<=i;v++)
	    	for(int w=0;w<m;w++)
	    		if(flag[v][w]!='W')
	    		    wcnt++;
	    for(int j=i+1;j<n-1;j++)
	    {
	    	bcnt=0;
	    	rcnt=0;
	    	for(int v=i+1;v<=j;v++)
	    		for(int w=0;w<m;w++)
	    			if(flag[v][w]!='B')
	    		    	bcnt++;
	    	for(int v=j+1;v<n;v++)
	    		for(int w=0;w<m;w++)
	    			if(flag[v][w]!='R')
	    		    	rcnt++;
	    	cnt=wcnt+bcnt+rcnt;
	    	if(mn>cnt)
	    		mn=cnt;
	    }
	}
	cout<<mn;
	return 0;
}