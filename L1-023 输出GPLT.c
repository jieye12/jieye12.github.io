����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰�GPLTGPLT....������˳������������������ַ�����Ȼ�������ַ��������ִ�Сд���ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�GPLT��˳���ӡ��ֱ�������ַ����������

�����ʽ��
������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��
��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
���������
GPLTGPLTGLTGLGLL
#include<stdio.h>
#include<string.h>
int main()
{
    char a[11111];
    int i,k,count[5]={0},max=1;
    scanf("%s",a);
    k=strlen(a);
    for(i=0;i<k;i++)
    {
        if(a[i]=='G'||a[i]=='g')
            count[1]++;
        if(a[i]=='P'||a[i]=='p')
            count[2]++;
        if(a[i]=='L'||a[i]=='l')
            count[3]++;
        if(a[i]=='T'||a[i]=='t')
            count[4]++;
    }
    for(i=1;i<5;i++)
    {
        if(count[i]>max)
            max=count[i];
    }
    for(i=1;i<=max;i++)
    {
        if(count[1]>0)
        {
            printf("G");
            count[1]--;
        }
        if(count[2]>0)
        {
            printf("P");
            count[2]--;
        }
        if(count[3]>0)
        {
            printf("L");
            count[3]--;
        }
        if(count[4]>0)
        {
            printf("T");
            count[4]--;
        }
    }
    return 0;
}

