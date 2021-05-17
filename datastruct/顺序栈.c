#include<stdio.h>
#define MAX 100
typedef int datatype;
typedef struct
{
    datatype data[MAX];
    int top;
}Seqstack;
Seqstack *Init_Seqstack()
{
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    s->top=-1;
    return s;
}
int Judge_Seqstack(Seqstack *s)
{
    if(s->top==-1) return 1;
    else return 0;
}
int Push_Seqstack(Seqstack *s,datatype e)
{
    if(s->top==MAX-1) return -1;
    else
    {
        s->top++;
        s->data[s->top]=e;
        return 1;
    }
}
int Pop_Seqstack(Seqstack *s)
{
    if(s->top==-1) return -1;
    else
    {
        s->top--;
        return s->data[s->top+1];
    }
}
int Get_Seqstack(Seqstack *s)
{
    if(s->top==-1) return -1;
    else
        return s->data[s->top];
}
int Input_Seqstack(Seqstack *s)
{
    int t;
    datatype e;
    do
    {
        scanf("%d",&e);
        t=Push_Seqstack(s,e);
        if(t==-1)
        {
            printf("超出顺序栈长度\n");
            return -1;
        }
    }while(getchar()!='\n');
    return 0;
}
void Output_Seqstack(Seqstack *s)
{
    printf("顺序栈为：");
    int t;
    t=s->top;
    while(t>=0)
    {
        printf("%d ",s->data[t]);
        t--;
    }
    printf("\n");
}
int main()
{
    int t,k;
    datatype e;
    Seqstack *s;
    s=Init_Seqstack();
    printf("请输入顺序栈：");
    t=Input_Seqstack(s);
    A:
    system("cls");
    Output_Seqstack(s);
    printf("************************\n");
    printf("菜单：\n0：退出程序\n1：判断空栈\n2：入栈\n3：出栈\n4：取出栈定元素\n");
    printf("************************\n功能选择为：");
    scanf("%d",&k);
    switch(k)
    {
        case 0:return 0;
        case 1:
            t=Judge_Seqstack(s);
            if(t==1)    printf("顺序栈为空\n");
            else printf("顺序栈不为空\n");
            break;
        case 2:
            printf("请输入入栈元素：\n");
            scanf("%d",&e);
            t=Push_Seqstack(s,e);
            if(t==-1) printf("顺序栈已满\n");
            else
                Output_Seqstack(s);
            break;
        case 3:
            t=Pop_Seqstack(s);
            if(s->top==-1) printf("顺序栈为空\n");
            else
            {
                printf("出栈元素为：%d\n",t);
                Output_Seqstack(s);
            }
            break;
        case 4:
            t=Get_Seqstack(s);
            if(s->top==-1) printf("顺序栈为空\n");
            else printf("栈定元素为：%d\n",t);
            break;
        default: printf("选择错误请重新选择\n"); goto A;
    }
    printf("\n\n输入回车继续");
    getchar();
    getchar();
    goto A;
}
