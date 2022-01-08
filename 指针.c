#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 40		//�༶���ѧ������

int k=1; 

typedef struct students//���ݽṹ�� 
{
	char name[20];		//ѧ������ 
	char sex[2];		//xyΪ�У�xxΪŮ��  
	char number[8];		//ѧ�� 
	int age;			//���� 
	int score_Math_Gao;	//�����ɼ� 
	int score_Math_Xian;//�ߴ��ɼ� 
	int score_Python;	//Python�ɼ� 
	int score_English;  //Ӣ��ɼ� 
//	int Score=score_Math_Gao+score_Math_Xian+score_Python+score_English;	//�ܳɼ� 
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
	printf("				��ϵͳΪѧ����Ϣ����ϵͳ,�����ʹ��.\n"); 
	printf("				����¼��ѧ����Ϣ���ٽ��в���.\n");
	printf("				�ǵñ���¼���ѧ����Ϣ\n");
	printf("						�ص����˵�\n");
	printf("****************************************************\n");
	printf("****************************************************\n");
	
}

void input()
{
	int n;
	printf("������¼����Ϣ��ѧ��������"); 
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
			printf("�������ѧ����������");
			scanf("%s",&newone->name);
			printf("�������ѧ�����Ա�") ;
			scanf("%s",&newone->sex);
			printf("�������ѧ����ѧ�ţ�");
			scanf("%s",&newone->number);
			printf("�������ѧ�������䣺");
			scanf("%d",&newone->age);
			printf("�������ѧ���ĸ����ɼ���");
			scanf("%d",&newone->score_Math_Gao);
			printf("�������ѧ�����ߴ��ɼ���");
			scanf("%d",&newone->score_Math_Xian);
			printf("�������ѧ����Python�ɼ���");
			scanf("%d",&newone->score_Python);
			printf("�������ѧ����Ӣ��ɼ���");
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
	printf("1:��������ѯ\n");
	printf("2:��ѧ�Ų�ѯ\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
				printf("������ѧ��������\n");
				scanf("%s",&name);
				while(current!=NULL)
				{
					if(strcmp(name,current->name)==0)
					{
					printf("��ѧ���ĸ����ɼ�Ϊ��");
					printf("%d\n",current->score_Math_Gao);
					printf("��ѧ�����ߴ��ɼ�Ϊ��");
					printf("%d\n",current->score_Math_Xian);
					printf("��ѧ����Python�ɼ�Ϊ��");
					printf("%d\n",current->score_Python);
					printf("��ѧ����Ӣ��ɼ�Ϊ��");
					printf("%d\n",current->score_English);
					break; 
					}
				}
				break; 
		case 2:
				printf("������ѧ��ѧ�ţ�\n");
				scanf("%s",&number);
				while(current!=NULL)
				{
					if(strcmp(number,current->number)==0)
					{
					printf("��ѧ���ĸ����ɼ�Ϊ��");
					printf("%d\n",current->score_Math_Gao);
					printf("��ѧ�����ߴ��ɼ�Ϊ��");
					printf("%d\n",current->score_Math_Xian);
					printf("��ѧ����Python�ɼ�Ϊ��");
					printf("%d\n",current->score_Python);
					printf("��ѧ����Ӣ��ɼ�Ϊ��");
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
		printf("��ǰ��δ¼��ѧ����Ϣ��\n");
	else
	{
		current=previous->next;
			if(current!=NULL)
			{
				printf("��������Ҫɾ����Ϣ��ѧ��������");
				scanf("%s",&name);
				while(current!=NULL)
				{
					if(strcmp(current->name,name)==0)
					{
						previous->next=current->next;
						flag=1;
						free(current);
						printf("��ѧ����Ϣ��ɾ����\n");
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
		printf("��������Ҫ�ı���Ϣ��ѧ��������");
	    scanf("%s",&name);
		while(current!=NULL)
		{
			if(strcmp(name,current->name)==0)
			{
				printf("��������Ҫ�ı�ѧ���ĳɼ����ͣ�\n");
				scanf("%s",&mes);                            
				if(strcmp(mes,"�����ɼ�")==0)
				{
					printf("����������ɼ���\n");
					scanf("%d",&current->score_Math_Gao);
				}
				else if(strcmp(mes,"�ߴ��ɼ�")==0)
				{
					printf("�������ߴ��ɼ���\n");
					scanf("%d",&current->score_Math_Xian);
				}
				else if(strcmp(mes,"Python�ɼ�")==0)
				{
					printf("������Python�ɼ���\n");
					scanf("%d",&current->score_Python);
				}
				else if(strcmp(mes,"Ӣ��ɼ�")==0)
				{
					printf("������Ӣ��ɼ���\n");
					scanf("%d",&current->score_English);
				} 
				printf("�޸ĳɹ���\n");
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
	printf("  ����    �Ա�   	ѧ��   ����     �����ɼ�     �ߴ��ɼ�    Python�ɼ�     Ӣ��ɼ�\n"); 
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
		printf("*\t\t\t		   *��ӭ����ѧ����Ϣ����ϵͳ*     		\t\t\t*\n");
		printf("*\t\t\t\t             *ϵͳ���ܲ˵�*				\t\t\t\t*\n");
		printf("*\t\t\t	No1:ϵͳ˵��		No2:¼��ѧ����Ϣ	\t\t\t*\n");
		printf("*\t\t\t	No3:��ȡѧ����Ϣ        No4:����ѧ����Ϣ	\t\t\t\t*\n");
		printf("*\t\t\t	No5:ѧ����Ϣ����    	No6:ɾ��ѧ����Ϣ	\t\t\t\t*\n");
		printf("*\t\t\t	No7:�޸�ѧ����Ϣ		\t\t\t\t\t\t*\n");
		printf("*\t\t				No0:�˳�ϵͳ					\t\t\t\t*");
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n") ;
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\n");
		printf("��ѡ��˵���ť��\n");
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
			   	printf("				�˳�ϵͳ��\n");
				break;
			default:
			   	printf("����0~8֮��ѡ��");	
		}
	}
	
	return 0;
}
