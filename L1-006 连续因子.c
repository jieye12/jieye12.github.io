一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2 
31
 ）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630
输出样例：
3
5*6*7
#include<stdio.h>
#include<math.h>
int is_prime(int x){
    int i;
    if(x==1)return 1;
    for(i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i,N,flag,len,sum,lenm,im;
    scanf("%d",&N);
    if(is_prime(N)){
        printf("1\n");
        printf("%d\n",N);
    }
    else {
        im=N;
        lenm=0;
        for(i=2;i<=sqrt(N);i++){
            if(N%i==0){
                if(im>i)im=i;
                sum=i;
                for(len=1;;len++){
                    sum*=(i+len);
                    if(N%sum)break;
                }
                len--;
                if(len>lenm){
                    lenm=len;
                    im=i;
                }
            }
        }
        printf("%d\n",lenm+1);
        for(i=0;i<lenm;i++)
            printf("%d*",im+i);
        printf("%d\n",im+i);
 
    }
}
