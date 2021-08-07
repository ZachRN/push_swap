#include <stdio.h>

int main(void)
{
	int a = (5&1);
	int b= (12&1);
	int c = (2>>4);
	int d = (87>>3);

	printf("a:%d\nb:%d\nc:%d\nd:%d\n",a,b,c,d);
	return (0);
}