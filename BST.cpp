#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *left_child;
	struct node *right_child;
	struct node  *father;
}RBT;
//节点的加入
void insert_node(RBT **tree, int num) {
	RBT *temp = NULL;
	temp = (RBT*)malloc(sizeof(RBT));
	temp->value = num;
	temp->left_child = NULL;
	temp->right_child = NULL;
	RBT *bj = NULL;

	if (*tree == NULL) {
		*tree = temp;
		temp->father = NULL;
		return;
	}
	bj = *tree;
	while (bj) {
		if (bj->value<num) {
			if (bj->right_child == NULL) {
				bj->right_child = temp;
				temp->father = bj;
				return;
			}
			bj = bj->right_child;
		}
		else if (bj->value>num) {
			if (bj->left_child == NULL) {
				bj->left_child = temp;
				temp->father = bj;
				return;
			}
			bj = bj->left_child;
		}
		else {
			printf("error\n");
			free(temp);
			temp = NULL;
			return;
		}
	}
}

//创建BST 树
void create(RBT **tree, int a[], int len) {
	if (a == NULL || len <= 0) return;
	for (int i = 0; i<len; i++) {
		insert_node(tree, a[i]);
	}
}

//先序遍历BST树
void Traver(RBT *tree) {
	if (tree == NULL)  return;
	printf("%4d", tree->value);
	Traver(tree->left_child);
	Traver(tree->right_child);
}

int main() {
	RBT *tree = NULL;
	int a[] = { 11,2,14,1,7,15,5,8 };
	create(&tree, a, sizeof(a) / sizeof(a[0]));
	Traver(tree);
	return 0;
}
