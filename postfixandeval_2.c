#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

int evalstack[MAX_STACK_SIZE];
precedence poststack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE] = {"6+7*2-(5+4)-9/3+(8-1)="};

static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

int eval(void);
void postfix(void);

void evalpush(int *top, char pre);
int evalpop(int *top);

void postpush(int *top, precedence pre);
precedence postpop(int *top);

precedence getToken(char *symbol, int *n);
void attachToken(precedence token, int *i);

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = 0;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			evalpush(&top, symbol-'0');
		else
		{
			op2 = evalpop(&top);
			op1 = evalpop(&top);
			switch (token) {
			case plus: evalpush(&top, op1 + op2);
				break;
			case minus: evalpush(&top, op1 - op2);
				break;
			case times: evalpush(&top, op1 * op2);
				break;
			case divide: evalpush(&top, op1 / op2);
				break;
			case mod: evalpush(&top, op1 % op2);
				break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return evalpop(&top);
}
void postfix(void)
{
	char symbol;
	precedence token;
	int i = 0;
	int n = 0;
	int top = 0;
	poststack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
		{
			printf("%c", symbol);
			expr[i++] = symbol;
		}
		else if (token == rparen)
		{
			while (poststack[top] != lparen)
				attachToken(postpop(&top), &i);
			postpop(&top);
		}
		else
		{
			while (isp[poststack[top]] >= icp[token])
				attachToken(postpop(&top), &i);
			postpush(&top, token);
		}
	}
	while ((token = postpop(&top)) != eos)
		attachToken(token, &i);
	expr[i] = '=';
	printf("\n");
}
void evalpush(int *top, char pre)
{
	if (*top >= MAX_STACK_SIZE - 1) {
		printf("StackFull.\n");
		return;
	}
	evalstack[++*top] = pre;
}
int evalpop(int *top)
{
	if (*top < 0) {
		printf("StackEmpty.\n");
		return -1;
	}
	return evalstack[(*top)--];
}
void postpush(int *top, precedence pre)
{
	if (*top >= MAX_STACK_SIZE - 1) {
		printf("StackFull.\n");
		return;
	}
	poststack[++*top] = pre;
}
precedence postpop(int *top)
{
	if (*top < 0) {
		printf("StackEmpty.\n");
		return eos;
	}
	return poststack[(*top)--];
}
precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '=': return eos;
	default: return operand;
	}
}
void attachToken(precedence token, int *i)
{
	switch (token)
	{
	case plus: printf("+"); expr[(*i)++] = '+';
		return;
	case minus: printf("-"); expr[(*i)++] = '-';
		return;
	case times: printf("*"); expr[(*i)++] = '*';
		return;
	case divide: printf("/"); expr[(*i)++] = '/';
		return;
	case mod: printf("%%"); expr[(*i)++] = '%';
		return;
	}
}
int main()
{
	int result;
	printf("\ninfix: 6+7*2-(5+4)-9/3+(8-1)=\n\n");
	printf("postfix: ");
	postfix();
	result = eval();
	printf("\nresult : %d\n", result);

	return 0;
}
