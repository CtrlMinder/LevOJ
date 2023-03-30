#include<stdio.h>
int main()
{
	int a,b,r,n,i;
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		int k,h;
		scanf("%d%d",&a,&b);
		k = a;
		h = b;
		while(a%b!=0)
		{
			r = a%b;
			a = b;
			b = r;
		}
		printf("%d\n",k*h/b);
	}
	return 0;
}