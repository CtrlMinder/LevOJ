#include<stdio.h>
int fun(int a,int b);
int main()
{
	int n,a,b,c,i;
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		int r;
		scanf("%d%d%d",&a,&b,&c);
		r = fun(a,fun(b,c));
		printf("%d\n",r);
	}
	return 0;
}
int fun(int a,int b)
{
	int r;
	while(a%b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return b;
}