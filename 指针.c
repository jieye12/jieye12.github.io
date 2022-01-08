#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40		//班级最大学生人数

int k=1; 

typedef struct students//数据结构体 
{
	char name[20];		//学生姓名 
	char sex[2];		//xy为男；xx为女；  
	char number[8];		//学号 
	int age;			//年龄 
	int score_Math_Gao;	//高数成绩 
	int score_Math_Xian;//线代成绩 
	int score_Python;	//Python成绩 
	int score_English;  //英语成绩 
//	int Score=score_Math_Gao+score_Math_Xian+score_Python+score_English;	//总成绩 
	struct students* next;
}Node;

Node*head;

void menu();
void illustration();
void input();
void seek();
void delete();
void modify();
void sort();
void display();

//int cmp(const void*a,const void*b)
//{
//	Node*aa=(Node*)a;
//	Node*bb=(Node*)b;
//	return((aa->score_Math_Gao+aa->score_Math_Xian+aa->score_Python+aa->score_English)>(bb->score_Math_Gao+bb->score_Math_Xian+bb->score_Python+bb->score_English));
//}

void illustration()
{
	printf("				此系统为学生信息管理系统,请谨慎使用.\n"); 
	printf("				请先录入学生信息，再进行操作.\n");
	printf("				记得保存录入的学生信息\n");
	printf("						回到主菜单\n");
	printf("****************************************************\n");
	printf("****************************************************\n");
	
}

void input()
{
	int n;
	printf("请输入录入信息的学生人数："); 
	scanf("%d",&n);
	Node *previous;
	Node *newone;
	previous=NULL;
	newone=(Node*)malloc(sizeof(Node));
	if(newone!=NULL)
	{
		head=newone;
		while(n--)
		{
			printf("请输入该学生的姓名：");
			scanf("%s",&newone->name);
			printf("请输入该学生的性别：") ;
			scanf("%s",&newone->sex);
			printf("请输入该学生的学号：");
			scanf("%s",&newone->number);
			printf("请输入该学生的年龄：");
			scanf("%d",&newone->age);
			printf("请输入该学生的高数成绩：");
			scanf("%d",&newone->score_Math_Gao);
			printf("请输入该学生的线代成绩：");
			scanf("%d",&newone->score_Math_Xian);
			printf("请输入该学生的Python成绩：");
			scanf("%d",&newone->score_Python);
			printf("请输入该学生的英语成绩：");
			scanf("%d",&newone->score_English);
			printf("\n");
			previous=newone;
			newone=(Node *)malloc(sizeof(Node));
			if(newone!=NULL)
				previous->next=newone;
		}
		previous->next=NULL;
	}
}

void seek()
{
	int a;
	char name[20];
	char number[8];
	Node*current;
	current=head;
	printf("1:按姓名查询\n");
	printf("2:按学号查询\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
				printf("请输入学生姓名：\n");
				scanf("%s",&name);
				while(current!=NULL)
				{
					if(strcmp(name,current->name)==0)
					{
					printf("该学生的高数成绩为：");
					printf("%d\n",current->score_Math_Gao);
					printf("该学生的线代成绩为：");
					printf("%d\n",current->score_Math_Xian);
					printf("该学生的Python成绩为：");
					printf("%d\n",current->score_Python);
					printf("该学生的英语成绩为：");
					printf("%d\n",current->score_English);
					break; 
					}
				}
				break; 
		case 2:
				printf("请输入学生学号：\n");
				scanf("%s",&number);
				while(current!=NULL)
				{
					if(strcmp(number,current->number)==0)
					{
					printf("该学生的高数成绩为：");
					printf("%d\n",current->score_Math_Gao);
					printf("该学生的线代成绩为：");
					printf("%d\n",current->score_Math_Xian);
					printf("该学生的Python成绩为：");
					printf("%d\n",current->score_Python);
					printf("该学生的英语成绩为：");
					printf("%d\n",current->score_English);
					break; 
					}
				}
				break; 
	}
	
}

void delete()
{
	char name[20];
	int flag=0;
	Node*previous;
	Node*current,*newone;
	previous=head;
	if(previous==NULL)
		printf("当前还未录入学生信息。\n");
	else
	{
		current=previous->next;
			if(current!=NULL)
			{
				printf("请输入需要删除信息的学生姓名：");
				scanf("%s",&name);
				while(current!=NULL)
				{
					if(strcmp(current->name,name)==0)
					{
						previous->next=current->next;
						flag=1;
						free(current);
						printf("该学生信息已删除。\n");
					}
					previous=current;
					current=current->next;
				}
			}
		}
		
}

void modify()
{
	char name[20],mes[20];
	Node*current;
	current=head;
	while(current!=NULL)
	{
		printf("请输入需要改变信息的学生姓名：");
	    scanf("%s",&name);
		while(current!=NULL)
		{
			if(strcmp(name,current->name)==0)
			{
				printf("请输入需要改变学生的成绩类型：\n");
				scanf("%s",&mes);                            
				if(strcmp(mes,"高数成绩")==0)
				{
					printf("请输入高数成绩：\n");
					scanf("%d",&current->score_Math_Gao);
				}
				else if(strcmp(mes,"线代成绩")==0)
				{
					printf("请输入线代成绩：\n");
					scanf("%d",&current->score_Math_Xian);
				}
				else if(strcmp(mes,"Python成绩")==0)
				{
					printf("请输入Python成绩：\n");
					scanf("%d",&current->score_Python);
				}
				else if(strcmp(mes,"英语成绩")==0)
				{
					printf("请输入英语成绩：\n");
					scanf("%d",&current->score_English);
				} 
				printf("修改成功！\n");
			}
			current=current->next;
		}
	}
}


void sort()
{
	
	
}


void display()
{
	Node*q=(Node*)malloc(sizeof(Node));
	q=head;
	printf("  姓名    性别   	学号   年龄     高数成绩     线代成绩    Python成绩     英语成绩\n"); 
	while(q!=NULL)
	{
		printf("  %s %s %s %5d  %6d   %10d  %10d  %10d\n",q->name,q->sex,q->number,q->age,q->score_Math_Gao,q->score_Math_Xian,q->score_Python,q->score_English);
		q=q->next;
	}
	printf("\n");
}

int main()
{
	int a,b,c;
	Node*head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	while(k)
	{
		int number;
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
		printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
		printf("\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("\n");
		printf("*\t\t\t		   *欢迎进入学生信息管理系统*     		\t\t\t*\n");
		printf("*\t\t\t\t             *系统功能菜单*				\t\t\t\t*\n");
		printf("*\t\t\t	No1:系统说明		No2:录入学生信息	\t\t\t*\n");
		printf("*\t\t\t	No3:读取学生信息        No4:查找学生信息	\t\t\t\t*\n");
		printf("*\t\t\t	No5:学生信息排序    	No6:删除学生信息	\t\t\t\t*\n");
		printf("*\t\t\t	No7:修改学生信息		\t\t\t\t\t\t*\n");
		printf("*\t\t				No0:退出系统					\t\t\t\t*");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n") ;
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\n");
		printf("请选择菜单按钮：\n");
		scanf("%d",&number);
		switch(number)
		{
			case 1:illustration();
			   	break;
			case 2:input();
			   	break;
		    case 3:display();
			   	break;
			case 4:seek();
			   	break;
			case 5:sort();
				break;
  			case 6:delete();
			   	break;
			case 7:modify();
			   	break;
			case 0:k=0;
			   	printf("				退出系统！\n");
				break;
			default:
			   	printf("请在0~8之间选择：");	
		}
	}
	
	return 0;
}
