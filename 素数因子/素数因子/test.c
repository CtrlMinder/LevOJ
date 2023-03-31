#include<stdio.h>
int fact(int x)//判断x是不是素数
{
int m;
if(x==2)
	return 1;
else
	{
		for(m = 2;m<x;m++)
		{
			if(x%m==0)
				return 0;
		}
    }
return 1;
}
int main()
{
	int n,i,flag;
	while((scanf("%d",&n))!=EOF)
	{
			for(i = 2;i<=n;)
			{
				if(n%i==0)
				{
					flag = 1;
					flag = fact(i);
					if(flag==1)
						printf("%d ",i);
					n = n/i;
				}
				else
					i++;
			}

		printf("\n");
	}
return 0;
}
