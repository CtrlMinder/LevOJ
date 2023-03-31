//#include<stdio.h>
//int main()
//{
//	int i,j,k,h,ch[100000] = {0};
//	i = 0;
//	j = 0;
//	while(1)
//	{
//		scanf("%d",&ch[i]);
//		if(ch[i]!=-1)
//			i++;
//		else
//			break;
//	}
//	for(k = 0;k<i;k++)
//	{
//		if(ch[k]>j)
//			j = ch[k];
//	}
//	for(k = 1;k<=j;k++)
//	{
//		int num = 0;
//		for(h = 0;h<i;h++)
//		{
//			if(ch[h]==k)
//				num++;
//		}
//		if(num)
//			printf("%d %d\n",k,num);
//	}
//	return 0;
//}
#include <stdio.h>
int main()
{
	int x[1000] = {0},y[1000] = {0};
	int i,n,j;
	for(i=1;x[i-1]!=-1;i++)
	    scanf("%d",&x[i]);
	//for(i=0;i<1000;i++)
	//    y[i]=0;
	for(j=1;j<i-1;j++)
	{
		y[x[j]]=y[x[j]]+1;
	}
	for(i=0;i<1000;i++)
	{
		if(y[i])
		printf("%d %d\n",i,y[i]);
	}
	return 0;
}
