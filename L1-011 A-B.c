本题要求你计算A?B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A?B。

输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10 
4
 ，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：
在一行中打印出A?B的结果字符串。

输入样例：
I love GPLT!  It's a fun game!
aeiou
输出样例：
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
