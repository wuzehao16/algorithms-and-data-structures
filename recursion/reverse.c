#include <stdio.h>

int main()
{
    printf("请输入想要反转的字符串，以#结尾。\n");
    print();
    return 0;
}

void print()
{
    char a;
    scanf("%c", &a);
    if( a != '#') print();
    if( a != '#') printf( "%c", a);
}
