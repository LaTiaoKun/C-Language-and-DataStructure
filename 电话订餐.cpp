// 电话订餐.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "windows.h"
#include "stdlib.h"
#include "string.h"
#define N 3
struct guest
{
	int number; char name[20]; int time; int att; char tele[15];
}list[N];
int count=0;
void Input(struct guest list[])
{
	printf(" -————————————————————\n");
	printf("|             客户信息登录平台            |\n");
	printf(" -----------------------------------------\n");
	printf(" -----------------------------------------\n");
	    printf("请输入编号");
		scanf_s("%d", &list[count].number, 10);
		printf("请输入姓名");
		scanf_s("%s", list[count].name,20);
		printf("请输入就餐人数");
		scanf_s("%d", &list[count].att, 10);
		printf("请输入就餐时间");
		scanf_s("%d", &list[count].time, 10);
		printf("请输入联系方式");
		scanf_s("%s", list[count].tele, 15);
		count++;
		printf("信息采集完毕。\n");
		getchar();
		printf("请按回车回到主菜单");
		getchar();
		system("cls");
}
int Search()
{
	printf(" -————————————————————\n");
	printf("|             客户信息查询平台            |\n");
	printf(" -----------------------------------------\n");
	printf(" -----------------------------------------\n"); 
	int i, number;
	printf("请输入要查询的编号：");
	scanf_s("%d", &number);
	for (i = 0; i < N; i++)
	{
		if (list[i].number == number)
		{
			printf("姓名：%s\t", list[i].name);
			printf("就餐人数：%d\t", list[i].att);
			printf("就餐时间：%d\t", list[i].time);
			printf("联系方式：%d");
			getchar();
			printf("请按回车回到主菜单");
			getchar();
			system("cls"); return 0;
		}
	}
	 printf("没有查询到.\n");
	 getchar();
	 printf("请按回车回到主菜单");
	 getchar();
	 system("cls");
}

void Update(struct guest list[])
{
	int i,t,number;
	printf(" -————————————————————\n");
	printf("|             客户信息修改平台            |\n");
	printf(" -----------------------------------------\n");
	printf(" -----------------------------------------\n"); 
  back:
	printf("修改信息---请输入编号\n");
	scanf_s("%d", &number);
	for (i = 0; i < N; i++)
	{
		if (list[i].number == number) goto Up;
	}   printf("没有查询到相关信息，请重新输入。\n"); goto back;
    Up:
	printf(" -----------------------------------------\n");
	printf("|              请选择修改信息             |\n");
	printf(" -----------------------------------------\n");
	printf("|                 1---姓名                |\n");
	printf(" -----------------------------------------\n");
	printf("|               2---就餐人数              |\n");
	printf(" -----------------------------------------\n");
	printf("|               3---就餐时间              |\n");
	printf(" -----------------------------------------\n");
	printf("|                 4---取消                |\n");
	printf(" -----------------------------------------\n");
				scanf_s("%d", &t);
				switch (t)
				{
    	    			case 1:scanf_s("%s", list[i].name); goto Up;
	     				case 2:scanf_s("%d", &list[i].att); goto Up;
						case 3:scanf_s("%d", &list[i].time); goto Up;
						case 4:break;
						default : printf("输入有误，请重新输入\n "); goto Up;
		        }
				getchar();
				printf("请按回车回到主菜单");
				getchar();
				system("cls");
  }

int Delete(struct guest list[])
{
	char c;
	int i,j,number;
	printf(" -————————————————————\n");
	printf("|             客户信息处理平台            |\n");
	printf(" -----------------------------------------\n");
	printf(" -----------------------------------------\n"); 
ip:
	printf("请输入编号：");
	scanf_s("%d", &number);
	for (i = 0; i < N; i++) 
	{ if (number == list[i].number) break; }
	printf("Cancel? “Y” or “N”  \n");
	getchar();
	scanf_s("%c", &c);
	if (c == 'Y') 
	{  
		for (j = i; j < count - 1; j++)
		{
			list[j].number = list[j + 1].number;
			for (c = 0; c < 20; c++) 
			{ list[j].name[c] = list[j + 1].name[c]; }
			list[j].time = list[j + 1].time;
			list[j].att = list[j + 1].att;
		}
		    list[count - 1] = { 0 };
	}
	else return 0;
	printf("信息处理完毕。");
	getchar();
	printf("请按回车回到主菜单");
	getchar();
	system("cls");
	

}

void Show(struct guest list[])
{
	int i;
	printf(" -————————————————————\n");
	printf("|             客户信息显示平台            |\n");
	printf(" -----------------------------------------\n");
	for (i = 0; i < count; i++)
	{
		printf(" -———————————---------\n");
		printf("|%d|\t%s|\t%d|\t%d|\n"
			, list[i].number, list[i].name, list[i].time, list[i].att);
	}
	    printf(" --------------------------------\n");
		getchar();
		printf("请按回车回到主菜单");
		getchar();
		system("cls");
}
int main()
{
 	int i;
start:
	printf(" -————————————————————\n");
	printf("|             综合信息处理平台            |\n");
	printf(" -----------------------------------------\n");
	printf("|               请选择服务。              |\n");
	printf(" -----------------------------------------\n");
	printf("|                1----插入                |\n");
	printf(" -----------------------------------------\n");
	printf("|                2----查询                |\n");
	printf(" -----------------------------------------\n");
	printf("|                3----修改                |\n");
	printf(" -----------------------------------------\n");
	printf("|                4----删除                |\n");
	printf(" -----------------------------------------\n");
	printf("|                5----显示                |\n");
	printf(" -----------------------------------------\n");
	printf("|                6----退出                |\n");
	printf(" -----------------------------------------\n");
	scanf_s("%d", &i);
    switch (i)
	{
	    case 1: Input(list); system("cls"); goto start;
		case 2: Search(); system("cls"); goto start;
	    case 3: Update(list); system("cls"); goto start;
		case 4: Delete(list); system("cls"); goto start;
		case 5: Show(list); system("cls"); goto start;
		case 6:break;
		default: printf("输入有误，请重新输入\n "); system("cls"); goto start;
    }
	printf("感谢您使用客户信息综合处理平台。");
	return 0;
}
