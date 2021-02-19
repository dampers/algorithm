#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) (a)^=(b)^=(a)^=(b)
#define endl '\n'
typedef long long lld;

struct Node
{
	char name;
	struct Node* left_child;
	struct Node* right_child;
};

void preorder(struct Node* nodeP)
{
	cout << nodeP->name;
	if(nodeP->left_child != 0)
		preorder(nodeP->left_child);
	if(nodeP->right_child != 0)
		preorder(nodeP->right_child);
}

void inorder(struct Node* nodeP)
{
	if(nodeP->left_child != 0)
		inorder(nodeP->left_child);
	cout << nodeP->name;
	if(nodeP->right_child != 0)
		inorder(nodeP->right_child);
}

void postorder(struct Node* nodeP)
{
	if(nodeP->left_child != 0)
		postorder(nodeP->left_child);
	if(nodeP->right_child != 0)
		postorder(nodeP->right_child);
	cout << nodeP->name;
}

struct Node* tree[26];

void init_tree()
{
	for(int i=0;i<26;i++) tree[i] = (struct Node*)malloc(sizeof(struct Node));
}

int main()
{
	int n;
	scanf("%d", &n);
	init_tree();
	for(int i=0;i<n;i++)
	{
		char parent, left, right;
		scanf(" %c %c %c", &parent, &left, &right);
		tree[i]->name = (char)i+'A';
		if(left == '.')
		{
			tree[parent-'A']->left_child = 0;
		}
		else tree[parent-'A']->left_child = tree[left-'A'];
		if(right == '.')
		{
			tree[parent-'A']->right_child = 0;
		}
		else tree[parent-'A']->right_child = tree[right-'A'];

	}
	preorder(tree[0]);
	cout << endl;
	inorder(tree[0]);
	cout << endl;
	postorder(tree[0]);
	return 0;
}