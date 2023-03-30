#include<stdio.h>
void fun(int n,int ch[4]);
int main()
{
	int ch[4],i,j,temp,count,max,min,n;
	while((scanf("%d",&n))!=EOF)
	{
		count = 0;
		fun(n,ch);
		while(n!=6174)
		{
			for(i = 0;i<3;i++)
				for(j = 0;j<3-i;j++)
					if(ch[j]>ch[j+1])
					{
						temp = ch[j];
						ch[j] = ch[j+1];
						ch[j+1] = temp;
					}
					max = ch[3]*1000+ch[2]*100+ch[1]*10+ch[0];
					min = ch[0]*1000+ch[1]*100+ch[2]*10+ch[3];
					n = max-min;
					fun(n,ch);
					count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
void fun(int n,int ch[4])
{
	ch[3] = n%10;
	ch[2] = n/10%10;
	ch[1] = n/100%10;
	ch[0] = n/1000;
}