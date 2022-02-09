一群人坐在一起，每人猜一个 100 以内的数，谁的数字最接近大家平均数的一半就赢。本题就要求你找出其中的赢家。

输入格式：
输入在第一行给出一个正整数N（≤10 
4
 ）。随后 N 行，每行给出一个玩家的名字（由不超过8个英文字母组成的字符串）和其猜的正整数（≤ 100）。

输出格式：
在一行中顺序输出：大家平均数的一半（只输出整数部分）、赢家的名字，其间以空格分隔。题目保证赢家是唯一的。
#include<stdio.h>
#include<math.h>
int main()
{
    int N,i,b[11111],c[11111],sum=0,average=0,min=11111,k=0;
    char a[11111][10];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s %d",a[i],&b[i]);
        sum+=b[i];
    }
    average=sum/(2*N);
    for(i=0;i<N;i++)
        c[i]=abs(b[i]-average);
    for(i=0;i<N;i++)
    {
        if(c[i]<min)
        {
            min=c[i];
            k=i;
        }
    }
    printf("%d %s",average,a[k]);
    return 0;
}
