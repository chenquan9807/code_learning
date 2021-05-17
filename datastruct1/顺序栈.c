#include<stdio.h>
#define MAXSSIZE 100
typedef int datatype;
typedef struct
{
    datatype data[MAXSSIZE];
    int top;
}Seqstack;
Seqstack *Init_sstack()
{
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    if(s) {s->top=-1;printf("置空成功\n");}
    return s;
}
int Empty_SStack(Seqstack *s)
{
    if(s->top==-1) return 1;
    else return 0;
}
int Push_SStack(Seqstack *s,datatype e)
{
    if(s->top==MAXSSIZE-1) return 0;
    else
    {
        s->top++;
        s->data[s->top]=e;
        return 1;
    }
}
void Out_SStack(Seqstack *s)
{
    int k;
    k=s->top;
    if(s->top==-1) {printf("顺序栈为空\n");return 0;}
    printf("顺序栈为：");
    while(s->top>=0)
    {
        printf("%d ",s->data[s->top]);
        s->top--;
    }
    printf("\n");
    s->top=k;
}
int Pop_SStack(Seqstack *s,datatype *e)
{
    if(Empty_SStack(s)) return 0;
    else
    {
        *e=s->data[s->top];
        s->top--;
        return  1;
    }
}
int Gettop_SStack(Seqstack *s)
{
    if(Empty_SStack(s)) return 0;
    else return (s->data[s->top]);
}
Seqstack *Creat_sstack()
{
    int e;
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    s->top=-1;
    do
    {
        scanf("%d",&e);
        s->top++;
        s->data[s->top]=e;
    }while(getchar()!='\n');
    printf("请输入回车");
    return s;
}
int Get_Seqstack(Seqstack *s,int i)
{
     if(s->top==-1) {printf("顺序栈为空\n");return 0;}
    if(i>=MAXSSIZE) return -1;
    s->top=i-1;
    return  s->data[s->top];
}                                   //按序号查找
int Locate_Seqstack(Seqstack *s,int i)
{
    int k;
    k=s->top;
    if(s->top==-1) {printf("顺序栈为空\n");return 0;}
    while(s->top>=0)
    {
        if(s->data[s->top]==i)
             return ++s->top;
        s->top--;
    }
    s->top=k;
    return -1;
}                                      //按数据查找
int main()
{
    Seqstack *s;
    int n,m,i;
    datatype e;
    printf("创建一个顺序栈，输入回车结束输入\n");
    s=Creat_sstack();
A:
    getchar();
    printf("\n请输入回车继续");
    getchar();
    system("cls");
    Out_SStack(s);
    printf("****************************\n");
    printf("请数字选择对顺序栈的操作\n0：操作结束\n1：置空栈\n2：判断空栈\n3：入栈\n4：出栈\n5：取出栈顶元素\n6：输出顺序栈\n7：重新输入顺序栈\n8：按位置查找元素\n9：按数值查找元素\n");
    printf("****************************\n");
    printf("功能选择为：");
    scanf("%d",&n);
    switch(n)
    {
        case 0:break;
        case 1:s=Init_sstack();goto A;
        case 2:
        {
            m=Empty_SStack(s);
            if(m==1)    printf("栈为空栈\n");
            else    printf("栈不为空\n");
            goto A;
        }
        case 3:
            {
                printf("请输入入栈元素e: ");
                scanf("%d",&e);
                m=Push_SStack(s,e);
                if(m==0)    printf("栈满不能入栈\n");
                else printf("入栈成功\n");
                goto A;
            }
        case 4:
            {
                m=Pop_SStack(s,&e);
                if(m!=0)    printf("出栈成功,出栈元素为%d\n",e);
                else    printf("出栈失败\n");
                goto A;
            }
        case 5:
            {
                m=Gettop_SStack(s);
                if(m==0)    printf("取出失败\n");
                else    printf("栈顶元素为%d\n",m);
                goto A;
            }
        case 6:Out_SStack(s); goto A;
        case 7:
            {
                printf("创建一个顺序栈，输入回车结束输入\n");
                s=Creat_sstack();
                printf("创建的顺序栈为：");
                Out_SStack(s);
            }
            goto A;
        case 8:
            {
                printf("请输入查找位置i:");
                scanf("%d",&i);
                e=Get_Seqstack(s,i);
                if(e==-1)
                    printf("不存在第%d位元素\n");
                else
                    printf("第%d位为%d\n",i,e);
                goto A;
            }
        case 9:
            {
                printf("请输入查找数值i：");
                scanf("%d",&i);
                e=Locate_Seqstack(s,i);
                if(e==-1) printf("不存在数值为%d的元素\n",i);
                if(e!=-1&&e!=0)
                    printf("数值位%d的元素位于第%d位\n",i,e);
                goto A;
            }
        default:printf("选择错误，请重新选择\n");goto A;
    }
    return 0;
}





