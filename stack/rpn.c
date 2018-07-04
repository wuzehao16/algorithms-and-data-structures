#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10
typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }
    s ->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT)* sizeof(ElemType)) ;
        if( !s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if( s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    sqStack s;
    char c;
    double d, e;
    char str[MAXBUFFER];
    int i = 0;

    InitStack(&s); //初始化栈
    printf("请输入逆波兰表达式，数据与运算符直接用空格隔开，输入#符号表示结束！\n");
    scanf("%c",&c);
    while(c != '#')
    {
        //过滤数字
        while( isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i]= '\0';
            if(i>= 10)
            {
                printf("输入的单个数据过大！\n");
                return -1;
            }
            scanf("%c", &c);
            if( c == ' ')
            {
                d = atof(str);
                Push(&s, d);
                i = 0;
                break;
            }
        }
        switch( c )
        {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d + e);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d - e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d * e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if(e != 0)
                {
                    Push(&s, d / e);
                } else{
                    printf("\n出错：除数为零\n");
                    return -1;
                }
                break;
        }
        scanf("%c", &c);
    }
    Pop(&s, &d);
    printf("结果为:%f", d);
    return 0;
}


