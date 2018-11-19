#include<bits/stdc++.h>

using namespace std;

typedef struct node *pnode;

typedef struct node{
	int a;
	pnode link;
};

pnode table[5] = {NULL} ;

void insert(int data)
{
	int index = data%5;
	pnode insert = (pnode)malloc(sizeof(node));
	insert-> a = data;
	insert->link = NULL;
	if(table[index] == NULL)
	{
		table[index] = insert;
		return;
	}
	pnode next = table[index];
	while(1)
	{
		if(next->link == NULL)
		{
			next->link = insert;
			return;
		}
		else
		{
			next = next->link;
		}
	}	
}

int search (int data)
{
	int index = data%5;
	pnode comp = table[index];
	if(comp==NULL) return 1;
	while(comp)
	{
		if(comp->a == data)
		{
			return 0;
		}
		else
		{
			comp = comp->link;
		}
	}
	return 1;
}

int del (int data)
{
	int index = data%5;
	pnode comnode = table[index];
	if(comnode==NULL) return 1;
	
	if(table[index]->a == data)
	{
		if(tabel[index]->link == NULL)
		{
			free(table[index]);
			table[index] = NULL;
		}
		else
		{
			table[index] = table[index]->link;
			free(comnode);
		}
		return 0;
	}
	pnode prenode = comnode;
	pnode comnode = comnode->link;
	while(comnode)
	{
		if(comnode->a == data)
		{
			if(comnode->link == NULL)
			{
				prenode->link == NULL;
				free(comnode);  
			}
			else
			{
				prenode->link = comnode->link;
				free(comnode);
			}
			return 0; 
		}
		else
		{
			prenode = comnode;
			comnode = comnode->link;
		}
	}
	return 1; 
}

int main()
{
	
	return 0;
}
