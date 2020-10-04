# include <stdio.h>

int pos = 0, end = 0;
int que[10000];
char order[10];

void push (int p)
{
	que[end++] = p;
}

void pop()
{
	if(que[pos])
	{
		
		printf("%d\n", que[pos]);
		que[pos] = 0;
		pos++;
	}
	else printf("-1\n");
}

void sizek()
{
	printf("%d\n", end-pos);
}

void empty()
{
	if(end-pos) printf("0\n");
	else printf("1\n");
}

void front()
{
	if(que[pos]) printf("%d\n", que[pos]);
	else printf("-1\n");
}

void back()
{
	if(que[end-1]) printf("%d\n", que[end-1]);
	else printf("-1\n");
}


int main()
{
	int t, i, j;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%s", order);
		if(strcmp(order, "push") == 0)
		{
			int k;
			scanf("%d", &k);
			push(k);
		}
		else if(strcmp(order,"pop")==0)
		{
			pop();
		}
		else if(strcmp(order,"size")==0)
		{
			sizek();
		}
		else if(strcmp(order,"empty")==0)
		{
			empty();
		}
		else if(strcmp(order,"front")==0)
		{
			front();
		}
		else if(strcmp(order,"back")==0)
		{
			back();
		}
		for(j=0;j<10;j++)
		{
			order[j] = '\0';
		}
	}
	return 0;
}
