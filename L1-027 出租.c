һʱ������һƬ����������������ô�ơ���ʵ��δ���ܼ򵥣�index�������arr������±꣬index[0]=2 ��Ӧ arr[2]=1��index[1]=0 ��Ӧ arr[0]=8��index[2]=3 ��Ӧ arr[3]=0���Դ����ơ��� �����׵õ��绰������18013820100��

����Ҫ�����дһ������Ϊ�κ�һ���绰����������δ��� ���� ��ʵ�ϣ�ֻҪ������ǰ�����оͿ����ˣ����������ǲ���ġ�

�����ʽ��
������һ���и���һ����11λ������ɵ��ֻ����롣

�����ʽ��
Ϊ����ĺ������ɴ����ǰ���У�����arr�е����ֱ��밴�ݼ�˳�������
#include<stdio.h>
int main()
{
    int b[10]={0},i,j,c[10],count=0,d[12];
    char a[12];
    scanf("%s",a);
    for(i=0;i<11;i++)
    {
        for(j=0;j<10;j++)
        {
            if((a[i]-'0')==j)
            {
                b[j]++;
                break;
            }
        }
    }
    for(i=9;i>=0;i--)
    {
        if(b[i]>0)
        {
            c[count]=i;
            count++;
        }
    }
    for(i=0;i<11;i++)
    {
        for(j=0;j<count;j++)
        {
            if((a[i]-'0')==c[j])
            {
                d[i]=j;
                break;
            }
        }
    }
    printf("int[] arr = new int[]{%d",c[0]);
    for(i=1;i<count;i++)
        printf(",%d",c[i]);
    printf("};\n");
    printf("int[] index = new int[]{%d",d[0]);
    for(i=1;i<11;i++)
        printf(",%d",d[i]);
    printf("};");
    return 0;
}
