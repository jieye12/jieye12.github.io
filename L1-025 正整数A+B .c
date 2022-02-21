题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。

输入样例1：
123 456
输出样例1：
123 + 456 = 579
输入样例2：
22. 18
输出样例2：
? + 18 = ?
输入样例3：
-100 blabla bla...33
输出样例3：
? + ? = ?
#include<stdio.h>
// #include<stdlib.h>
#include<string.h>
// #include<math.h>
int main()
{
    char a[1000],b[1000];
    scanf("%s",&a);
    gets(b);//两种输入方式结合，避免读不出第二个字符串开头的空格，其中一个测试点
    int A=0,B=0,flaga=1,flagb=1;int x=1;
    for(int i = strlen(a)-1; i >=0; i --)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)
        {
            A+=(a[i]-'0')*x;//转换成整数类型
            x*=10;
            if(a[0]=='0'||A>1000)flaga=0;//题目范围要求，最后两个测试点
        }
        else
        {
            flaga=0;
        }
    }int y=1;
    for(int i = strlen(b)-1; i >=1; i --)
    {

        if(b[i]-'0'>=0&&b[i]-'0'<=9)
        {
            B+=(b[i]-'0')*y;
            y*=10;
            if(b[1]=='0'||B>1000)flagb=0;
        }
        else
        {
            flagb=0;
        }
    }
    if(flaga&&flagb)
        printf("%d + %d = %d",A,B,A+B);
    else if(flaga)
        printf("%d + ? = ?",A);
    else if(flagb)
        printf("? + %d = ?",B);
    else
        printf("? + ? = ?");

    return 0;
}
