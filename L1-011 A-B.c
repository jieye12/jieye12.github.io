����Ҫ�������A?B�������鷳���ǣ�A��B�����ַ��� ���� �����ַ���A�а��ַ���B���������ַ�ȫɾ����ʣ�µ��ַ���ɵľ����ַ���A?B��

�����ʽ��
������2�����Ⱥ�����ַ���A��B�����ַ����ĳ��ȶ�������10 
4
 �����ұ�֤ÿ���ַ��������ɿɼ���ASCII��Ϳհ��ַ���ɣ�����Ի��з�������

�����ʽ��
��һ���д�ӡ��A?B�Ľ���ַ�����

����������
I love GPLT!  It's a fun game!
aeiou
���������
I lv GPLT!  It's  fn gm!
#include<stdio.h>
#include<string.h>
int main()
{
    char a[20000],b[20000],c[20000];
    int l1,l2,i,j,flag,k=0;
    gets(a);
    gets(b);
    l1=sizeof(a)/sizeof(a[1]);
    l2=sizeof(b)/sizeof(b[1]);
    for(i=0;i<l1;i++)
    {
        flag=1;
        for(j=0;j<l2;j++)
        {
            if(a[i]==b[j])
            {
                flag=10;
                break;
            }
        }
        if(flag==1)
        {
            c[k]=a[i];
            k++;
        }
            
    }
    puts(c);
    return 0;
}
