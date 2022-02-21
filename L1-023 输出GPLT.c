给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按GPLTGPLT....这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
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

