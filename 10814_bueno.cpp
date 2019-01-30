#include <bits/stdc++.h>

using namespace std;

typedef struct node *pnode;
typedef struct node
{
	char name[102];
	pnode link;
};

pnode a[201] = {NULL}; 

int main() {
	
	int n;
	pnode temp, pretemp;
	
	scanf("%d", &n);
	
	for(int i = 0; i<n ; i++)
	{
		int age; char tname[102];
		scanf("%d %s", &age, &tname);
		
		if(a[age] == NULL){
		a[age] = (pnode)malloc(sizeof(node));
		strcpy(a[age]->name, tname);
		a[age]->link = NULL;
		}
		
		else
		{
			temp = a[age];
			while(temp)
			{	
				pretemp = temp;
				temp = temp->link;		
			}
			
			if(temp == NULL){
					pretemp->link = (pnode)malloc(sizeof(node));
					pretemp = pretemp->link;
					strcpy(pretemp->name, tname);
					pretemp->link = NULL;
				}
		}
		
		memset(tname, 0, 101);
	}
	
	
	for(int i = 1; i<201; i++)
	{
		if(a[i] != NULL)
		{
			temp = a[i];
			while(temp)
			{
				printf("%d %s\n", i, temp->name);
				temp = temp->link;
			}
			
		}
	}

	return 0;
}