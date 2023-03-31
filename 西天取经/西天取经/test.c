#include<stdio.h>
long fun(int k,long ch[10000]);
int main()
{
	int n,k,i,j;
	while((scanf("%d",&n))!=EOF)
	{
		long sum = 0;
		for(i = 0;i<n;i++)
		{
			long ch[10000] = {0};
			scanf("%d",&k);
			for(j = 0;j<k;j++)
				scanf("%ld",&ch[j]);
			sum = sum+fun(k,ch);
		}
		printf("%ld\n",sum);
	}
	return 0;
}
long fun(int k,long ch[10000])
{
	long max = 0;
	int i;
	for(i = 0;i<k;i++)
	{
		if(ch[i]>max)
			max = ch[i];
	}
	return max;
}