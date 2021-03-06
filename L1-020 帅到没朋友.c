L1-020 帅到没朋友 (20 分)
当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。本题就要求你找出那些帅到没有朋友的人。

输入格式：
输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；随后N行，每行首先给出一个正整数K（≤1000），为朋友圈中的人数，然后列出一个朋友圈内的所有人——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（≤10000），为待查询的人数；随后一行中列出M个待查询的ID，以空格分隔。

注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋友圈的人。虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超过1的朋友圈里都至少有2个不同的人。

输出格式：
按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多余空格。如果没有人太帅，则输出No one is handsome。

注意：同一个人可以被查询多次，但只输出一次。
#include <stdio.h>
int main()
{
	int a[1000000]={ 0 };
	int N,K,M; 
	int i,n,m,sum=0;//sum是标志符，一举两用，在是否输出空格和是否找到太帅的人做标记 
	scanf("%d",&N); 
	while(N--)
	{
		scanf("%d",&K);
		for(i=1;i<=K;i++)
		{
			scanf("%d",&n);//避免有些只有一个人的朋友圈重复添加产生的影响
			if(K!=1)
			{
				a[n]+=K;//a[n]=1;//此人不帅
			}	 
		}
	}
	scanf("%d",&M);	
	while(M--)
	{
		scanf("%d",&m);
		if(a[m]==0)
		{
			if(sum!=0) printf(" ");//按输出格式的 
			printf("%05d",m);// '%05d',输出占五位，不足者用0补位  
			a[m]=1;//输出后，做标记，避免重复查询 
			sum++; 
		}		
	}
	if(sum==0) printf("No one is handsome");
	return 0;
}
