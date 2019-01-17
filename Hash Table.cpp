#include<stdio.h>
#include<iostream>
#include<string.h>
#include<String>
using namespace std;
#define Max 30
typedef struct Box
{
	char name[30];
	int ASCII;
};
typedef struct HASH
{
	Box*elem;
	int count;
}HashTable;

int initHASH(HashTable &e)
{
//	e = (HashTable*)malloc(sizeof(HashTable));
  e.elem = (Box*)malloc(sizeof(Box)*Max);
	for (int i = 0; i < Max; i++)
	{
		e.elem[i].ASCII = -1;
	}
	e.count = 0;
return 0;
}
int  insertHASH(HashTable *e,std::string  name)
{
	int count=0;
	int ASCII=0;
	char  *p = NULL;
	p = &name[0];
	while (*p != '\0')
	{
		if ((*p)>='A'&&  (*p) <= 'Z')
		{
			count += (*p);
		}
		p++;
	}
	ASCII = count;
	count %= 29;
	Box *box=&(e->elem[count]);
	p = &name[0];
	while (box->ASCII!=-1)
	{
		box++;
	}
	box->ASCII = ASCII;
	int 	i = 0;
	while (*p!='\0')
	{

		box->name[i] = *p;
		p++;
		i++;
	}
	
	e->count++;
	return 0;
}
int  searchHASH(HashTable e, std::string c)
{
	int countC = 0;
	Box *p = e.elem;
	char *b = &c[0];
	while (*b != '\0')
	{
		if ((*b) >= 'A' && (*b) <= 'Z')
		{
			countC += (*b);
		}
		b++;
	}

	int ASCII = countC % 29;
	p = &e.elem[ASCII];
	if (p->ASCII == ASCII)
	{
		for (int a = 0; a < 30; a++)
		{
			cout << p->name[a];
		}
		cout << endl;
		cout << p->ASCII << endl;
		cout << endl;
		return 1;
	}
	else
	{
		int i = ASCII;
		while (ASCII < Max)
		{
			if (p->ASCII = ASCII)
			{
				for (int a = 0; a < 30; a++)
				{
					if(p->name[a]!='\0')
					cout << p->name[a];
				}
				cout << endl;
				cout << p->ASCII << endl;
				cout << endl;
				return 1;
			}
			else
				p++;
				i++;

		}
	}
	return -1;
}
int main()
{
	HashTable P;
	initHASH(P);
	for (int i = 0; i < 5; i++)
	{

	char name[30];
	scanf_s("%s", name, 30);

	insertHASH(&P, name);
    }
	char i[30];
	scanf_s("%s", i, 30);
	searchHASH(P,i);
	return 0;
}