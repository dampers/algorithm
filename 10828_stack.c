# include <stdio.h>

int top = 0;
int stack[10000];
char order[10];

void push(int p)
{
	stack[top++] = p;
}

void pop()
{
	if(top)
	{
		printf("%d\n", stack[--top]);
		stack[top] = 0;
	}
	else printf("-1\n");
}

void size()
{
	printf("%d\n", top);
}

void empty()
{
	if(top) printf("0\n");
	else printf("1\n");
}

void topk()
{
	if(stack[top-1]) printf("%d\n", stack[top-1]);
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
			size();
		}
		else if(strcmp(order,"empty")==0)
		{
			empty();
		}
		else if(strcmp(order,"top")==0)
		{
			topk();
		}
		for(j=0;j<10;j++)
		{
			order[j] = '\0';
		}
	}
	return 0;
}
