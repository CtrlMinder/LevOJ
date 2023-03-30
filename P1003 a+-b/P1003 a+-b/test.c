#include<stdio.h>
int main()
{
	unsigned int a,b;
	int n,i;
	char s;
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		scanf("%u%c%u",&a,&s,&b);
		switch(s)
		{
		case '+':
			printf("%u\n",a+b);
			break;
		case '*':
			printf("%u\n",a*b);
			break;
		case '/':
			printf("%u\n",a/b);
			break;
		case '-':
			{
				if(a>=b)
					printf("%u\n",a-b);
				else
					printf("-%u\n",b-a);
			}
			break;
		}
	}
	return 0;
}