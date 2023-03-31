#include <stdio.h>
#include <math.h>
int min(int,int,int);
int main()
{
	int n,m,k,i;
	while((scanf("%d%d%d",&n,&m,&k))!=EOF)
	{
		for(i=sqrt(min(n,m,k)*1.0);0<i;i--)
		{

			if(n%i==0&&m%i==0&&k%i==0)
			break;
		}
		printf("%d\n",i);
	}
	return 0;
}
int min(int n,int m,int k)
{
	if(n<m)
	m=n;
	if(k<m)
	m=k;
	return m;
}