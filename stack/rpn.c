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

    InitStack(&s); //��ʼ��ջ
    printf("�������沨�����ʽ�������������ֱ���ÿո����������#���ű�ʾ������\n");
    scanf("%c",&c);
    while(c != '#')
    {
        //��������
        while( isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i]= '\0';
            if(i>= 10)
            {
                printf("����ĵ������ݹ���\n");
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
                    printf("\n��������Ϊ��\n");
                    return -1;
                }
                break;
        }
        scanf("%c", &c);
    }
    Pop(&s, &d);
    printf("���Ϊ:%f", d);
    return 0;
}


