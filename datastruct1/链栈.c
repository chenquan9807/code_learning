#include<stdio.h>
typedef int datatype;
typedef struct node                 //链栈的定义
{
    datatype data;
    struct node *next;
}Stacknode,*Linkstack;
Linkstack Init_Linkstack()          //链栈置空
{
    return NULL;
}
int Empty_Linkstack(Linkstack top)  //判断空栈
{
    if(top==NULL) return 1;
    else return 0;
}
Linkstack Push_Linkstack(Linkstack top,datatype e)      //入栈
{
    Stacknode *s;
    s=malloc(sizeof(Stacknode));
    s->data=e;
    s->next=top;
    top=s;
    return top;
}
Linkstack Pop_Linkstack(Linkstack top,datatype *e)      //出栈
{
    Stacknode *p;
    if(top==NULL) {printf("链栈为空栈\n");return NULL;}
    else
    {
        *e=top->data;
        p=top;
        top=top->next;
        free(p);
        printf("出栈成功，出栈元素为%d\n",*e);
        return top;
    }
}
datatype Gettop_Linkstack(Linkstack top)            //取栈顶元素
{
    if(top==NULL)return NULL;
    else return top->data;
}
Linkstack Creat_Linkstack()
{
    int e;
    Stacknode *p;
    p=Init_Linkstack();
    do
    {
        scanf("%d",&e);
        p=Push_Linkstack(p,e);
    }while(getchar()!='\n');
    return p;
}
void out_Linkstack(Linkstack top)                   //输出链栈
{
    Stacknode *p=top;
    if(p==NULL)                                      //排除空链栈
    {
        printf("空链表无法输出\n");
        return -1;
    }
    printf("该链栈为：\n栈顶||");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("||栈底\n");
}
void Num_Linkstack(Linkstack top,datatype e)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(s->data==e)
        {
            printf("该元素距栈顶第%d位\n",i);
            return;
        }
        s=s->next;
    }
    printf("链栈内不存在该数\n");
}
void Loc_Linkstack(Linkstack top,datatype e)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(i==e)
        {
            printf("距栈顶位置为第%d位的元素为%d\n",i,s->data);
            return;
        }
        s=s->next;
    }
    printf("链栈内不存在该位置\n");
}
Linkstack resort_Linkstack(Linkstack top,datatype e,int m)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(i==e)
        {
            s->data=m;
            out_Linkstack(top);
            return top;
        }
        s=s->next;
    }
    printf("链栈内不存在该位置\n");
    return top;
}
int main()
{
    int n,m;
    datatype e;
    Linkstack top;
    Stacknode *p;
    printf("创建链栈\n");
    top=Creat_Linkstack();
    out_Linkstack(top);
    A:
    printf("****************************\n");
    printf("请数字选择对链栈的操作\n0：结束操作\n1：修改元素\n2：判断空栈\n3：入栈\n4：出栈\n5：取出栈顶元素\n6：输出栈\n7：按值查找\n8：按位置查找\n");
    printf("****************************\n功能选择为：");
    scanf("%d",&n);
    switch(n)
    {
        case 0:printf("操作结束\n");return 0;
        case 1:
        {
            printf("请输入要修改位置：");
            scanf("%d",&e);
            printf("输入要修改后的数值：");
            scanf("%d",&m);
            top=resort_Linkstack(top,e,m);
            break;
        }
        case 2:
            {
                m=Empty_Linkstack(top);
                if(m==1)    printf("该链栈为空栈\n");
                else printf("该链栈不为空栈\n");
                break;
            }
        case 3:
            {
                printf("请输入入栈元素e:   ");
                scanf("%d",&e);
                top=Push_Linkstack(top,e);
                out_Linkstack(top);
                break;
            }
        case 4:
            {
                top=Pop_Linkstack(top,&e);
                out_Linkstack(top);
                break;
            }
        case 5:
            {
                e=Gettop_Linkstack(top);
                if(e==NULL) printf("链栈为空栈\n");
                else printf("栈顶元素为%d\n",e);
                break;
            }
        case 6:out_Linkstack(top);break;
        case 7:
            {
                printf("请输入查找数值:");
                scanf("%d",&e);
                Num_Linkstack(top,e);
                break;
            }
        case 8:
            {
                printf("请输入元素距栈顶位置i:");
                scanf("%d",&e);
                Loc_Linkstack(top,e);
                break;
            }
        default:printf("选择错误，请重新选择\n");break;
    }
    getchar();
    printf("请输入回车继续");
    getchar();
    system("cls");
    out_Linkstack(top);
    goto A;
}
