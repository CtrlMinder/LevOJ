#include<stdio.h>
int main()
{
	int n,k,i,j,a,b,count;
	while((scanf("%d%d",&n,&k))!=EOF)
	{
		int ch[100001] = {0};
		count = 0;
		for(i = 0;i<=n;i++)
			ch[i] = 1;
		for(i = 0;i<k;i++)
		{
			scanf("%d%d",&a,&b);
			for(j = a;j<=b;j++)
				ch[j] = 0;
		}
		for(i = 0;i<=n;i++)
		{
			if(ch[i]==1)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}