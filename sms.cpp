#include 
#include 
#include "student.h"
void Menu()
{
	printf("\n\n\n\n");
	printf("\t____________________________________________________________\n");
	printf("\t\t\t\t*学生信息管理系统*\n");
	printf("\t____________________________________________________________\n");
	printf("\t\t\t\t[1]插入\n");
	printf("\t\t\t\t[2]删除\n");
	printf("\t\t\t\t[3]修改\n");
	printf("\t\t\t\t[4]查找\n");
	printf("\t\t\t\t[5]浏览\n");
	printf("\t\t\t\t[6]保存\n");
	printf("\t\t\t\t[7]读取\n");
	printf("\t\t\t\t[0]退出\n");
	printf("\t_____________________________________________________________\n");
	printf("\n\t\t请选择(0-7):");
}
NodePtr InitList(NodePtr head)
{
	head=(NodePtr)malloc(sizeof(Node));
	(*head).next=NULL;
	return head;
}
void InsertFront(NodePtr head,Student e)
{
	NodePtr s;
	s=(NodePtr)malloc(sizeof(Node));
	(*s).date=e;
	(*s).next=(*head).next;
	(*head).next=s;
}
void Display(NodePtr head)
{
	head=(*head).next;
	if(head==NULL)
	{
		printf("空表\n");return;
	}
	printf("\t%10s%15s%4s%4s\n","num","name","sex","age");
	printf("\t_______________________________________\n");
	while(head)
	{
		printf("\t%10ld%15s%4c%4d\n",head->date.num,head->date.name,head->date.sex,head->date.age);
		head=head->next;
	}
}
void Delete(NodePtr head,NodePtr e)
{
	e=head;
}
NodePtr Search(NodePtr head,int num)
{
	NodePtr p;
	p=(NodePtr)malloc(sizeof(Node));
	p=head->next;
	while(p!=NULL&&p->date.num!=num)
		p=p->next;
	if(p->date.num=num)
		return p;
}
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
typedef struct Student
{
	long num;
	char name[20];
	char sex;
	int age;
}Student,*StudentPtr;
typedef struct Node
{
	Student date;
	struct Node* next;
}Node,*NodePtr;
void Menu();
NodePtr InitList(NodePtr head);
void InsertFront(NodePtr head,Student e);
void Delete(NodePtr head,NodePtr e);
NodePtr Search(NodePtr head,int num);
void Display(NodePtr head);
#endif // STUDENT_H_INCLUDED
#include 
#include 
#include "student.h"
#include 
#include
int main()
{
	int n;
	NodePtr head;
	head=InitList(head);
	Menu();
	scanf("%d",&n);
	printf("\n");
	while(n0)
	{
		switch(n)
		{
			case 1:
			{
				Student s;
				printf("请输入要插入的学生信息：(num name age sex)\n");
fflush(stdin); //清空
scanf("%ld%s%d %c",&s.num,s.name,&s.age,&s.sex);
InsertFront(head,s);
break;
}
case 2:
{
	int num;
	NodePtr s;
	printf("请输入要删除的学生学号：");
	scanf("%d",&num);
	s=Search(head,num);
	Delete(head,s);
	break;
}
case 3:printf("修改:\n");break;
case 4:
{
	NodePtr s;
	int num;
	printf("请输入要查找的学生学号：");
	scanf("%d",&num);
	s=Search(head,num);
	printf("\t%10ld%15s%4c%4d\n",s->date.num,s->date.name,s->date.sex,s->date.age);
	break;
}
case 5:Display(head);break;
case 6:printf("保存:\n");break;
case 7:printf("读取:\n");break;
}
getch();
Menu();
scanf("%d",&n);
printf("\n");
}
return 0;
}