һ�������� N �������п��ܴ����������������֡����� 630 ���Էֽ�Ϊ 3��5��6��7������ 5��6��7 ���� 3 �����������֡�������һ������ N��Ҫ���д���������������ӵĸ������������С�������������С�

�����ʽ��
������һ���и���һ�������� N��1<N<2 
31
 ����

�����ʽ��
�����ڵ� 1 �������������ӵĸ�����Ȼ���ڵ� 2 ���а� ����1*����2*����*����k �ĸ�ʽ�����С�������������У��������Ӱ�����˳�������1 �������ڡ�

����������
630
���������
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
