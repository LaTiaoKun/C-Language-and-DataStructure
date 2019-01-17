#include<iostream>
#include<math.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
using namespace std;

typedef struct BST
{
	int data;
	BST* lChild;
	BST* rChild;
}BST,*Bitree;
bool  Delete(Bitree t);
void in_order( Bitree t)//
{
	if (t == NULL)
	{
		return;
	}
	if(t->lChild!=NULL)
	in_order(t->lChild);
	cout << t->data << " ";
	if(t->rChild!=NULL)
	in_order(t->rChild);

	return;
}
void insert_tree(int data, Bitree &t)
{
	if (t == NULL)
	{
		t = new BST;
		t->data = data;
		t->lChild = NULL;
		t->rChild = NULL;
		return ;
	}


	if ((t->data)<data)
	{
		insert_tree(data, t->rChild);
	}
	if ((t->data)>data)
	{
		insert_tree(data, t->lChild);
	}
	return;
}
bool deleteBST(int x, Bitree &T)
{
	if (T == NULL)
	{
		return false;
	}
	if (T->data > x)
	{
		return deleteBST(x, T->lChild);
	}
	if (T->data < x)
	{
		return deleteBST(x, T->rChild);
    }
	if (T->data == x)
	{
		return Delete(T);
	}
}
bool Delete(Bitree t)
{
	Bitree q, s;
	if (t->lChild == NULL)
	{
		q = t;
		if (t->rChild)
			t = t->rChild;
		delete(q);
		
		return true;
	}
	if (t->rChild == NULL)
	{
		q = t;
		if(t->lChild)
		t = t->lChild;
		delete(q);
		return true;
	}
	q = t; s = t->lChild;
	while (s->rChild != NULL)
	{
		q = s;
		s = s->rChild;
	}
	t -> data = s->data;
	if (q!= t)
	{
		q->rChild = s->lChild;
	}
	else {
		q->lChild = s->lChild;
	}
	return true;
}
int main()
{
	Bitree tree =NULL;
	int data;
	cout << "请输入一个二叉搜索树" << endl;

	while (true)
	{
		cout << "请输入节点数据以0结束" << endl;
		cin >> data;
		cin.ignore();
		if (data != 0)
		{
			insert_tree(data, tree);
		}
		else  break;
	}
	cout << "请输入删除节点数据" << endl;
	cin >> data;
	deleteBST(data, tree);
	in_order(tree);
}

