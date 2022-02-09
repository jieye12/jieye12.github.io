一时间网上一片求救声，急问这个怎么破。其实这段代码很简单，index数组就是arr数组的下标，index[0]=2 对应 arr[2]=1，index[1]=0 对应 arr[0]=8，index[2]=3 对应 arr[3]=0，以此类推…… 很容易得到电话号码是18013820100。

本题要求你编写一个程序，为任何一个电话号码生成这段代码 —— 事实上，只要生成最前面两行就可以了，后面内容是不变的。

输入格式：
输入在一行中给出一个由11位数字组成的手机号码。

输出格式：
为输入的号码生成代码的前两行，其中arr中的数字必须按递减顺序给出。
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
