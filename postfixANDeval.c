#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos,operand} precedence;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int stack[MAX_SIZE];
char expr[MAX_SIZE] = {"6+7*2-(5+4)-9/3+(8-1)="};



void spush(int item)
{

}

int spop()
{

}


int eval()
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = getToken(&symbol, &n);
	while(token != eos)
	{
		if(token==operand)
			psuh(symbol-'0');
		else
		{
			op2 = pop();
			op1 = pop();
			switch(token)
			{
				case plus: push(op1+op2); break;
				case minus: push(op1-op2); break;
				case times: push(op1*op2); break;
				case divise: push(op1/op2); break;
				case mod: push(op1%op2); break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch(*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '/': return divide;
		case '%': return dod;
		case '*': return times;
		case ' ': return eos;
		case '=': return eos;
		default : return operand;
	}
}

void postfix()
{
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;
	stack[0] = eos;
	for(token=getToken(&symbol, &n);token!=eos;token=getToken(&symbol, &n))
	{
		if(token==operand)
			printf("%c", symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				printToken(pop());
			push(token);
		}
	}
	while((token=pop())!=eos)
		printToken(token);
	printf("\n");
	
}


int main()
{

	return 0;
}
