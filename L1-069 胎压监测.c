让我们把四个车轮 —— 左前轮、右前轮、右后轮、左后轮 —— 顺次编号为 1、2、3、4。本题就请你编写一个监测程序，随时监测四轮的胎压，并给出正确的报警信息。报警规则如下：

如果所有轮胎的压力值与它们中的最大值误差在一个给定阈值内，并且都不低于系统设定的最低报警胎压，则说明情况正常，不报警；
如果存在一个轮胎的压力值与它们中的最大值误差超过了阈值，或者低于系统设定的最低报警胎压，则不仅要报警，而且要给出可能漏气的轮胎的准确位置；
如果存在两个或两个以上轮胎的压力值与它们中的最大值误差超过了阈值，或者低于系统设定的最低报警胎压，则报警要求检查所有轮胎。
输入格式：
输入在一行中给出 6 个 [0, 400] 范围内的整数，依次为 1~4 号轮胎的胎压、最低报警胎压、以及胎压差的阈值。

输出格式：
根据输入的胎压值给出对应信息：

如果不用报警，输出 Normal；
如果有一个轮胎需要报警，输出 Warning: please check #X!，其中 X 是出问题的轮胎的编号；
如果需要检查所有轮胎，输出 Warning: please check all the tires!。
#include<stdio.h>
int main()
{
    int a[8],b[8],i,max,count=0;
    int c[4]={0};
    for(i=0;i<6;i++)
        scanf("%d",&a[i]);
    max=a[0];
    for(i=0;i<4;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    for(i=0;i<4;i++)
        b[i]=max-a[i];
    for(i=0;i<4;i++)
    {
        if(b[i]>a[5])
        {
            count++;
            c[i]=10;
        }
        else
        {
            if(a[i]<a[4])
            {
                count++;
                c[i]=10;
            }
        }
    }
    if(count==0)
        printf("Normal");
    else
    {
        if(count>1)
            printf("Warning: please check all the tires!");
        else
            for(i=0;i<4;i++)
            {
                if(c[i]==10)
                    printf("Warning: please check #%d!",(i+1));
            }
    }
   return 0;
}
