#include <stdio.h>

int main()
{
    printf("��������Ҫ��ת���ַ�������#��β��\n");
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
