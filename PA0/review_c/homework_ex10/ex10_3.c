#include <stdio.h>
int main()
{
	char *str1[] = {"gx", "qdx"};
	char *str2[] = {"GX", "QDX"};
	
	printf("str2[1] addr is %p, strform is %s\n\r", str2[1], str2[1]);
	printf("str1[1] addr is %p, strform is %s\n\r", str1[1], str1[1]);
	str2[1] = str1[1];
	printf("str2[1]addr is %p, strform is %s\n\r", str2[1], str2[1]);
	
}
