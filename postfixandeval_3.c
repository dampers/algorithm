#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos,operand} precedence;

int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int stack[MAX_SIZE];
char expr[MAX_SIZE] = {"6+7*2-(5+4)-9/3+(8-1)="};

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

void spush(int num, int *top)
{
	
}

int spop(int *top)
{

}


int main()
{

	return 0;
}