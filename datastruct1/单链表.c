#include<stdio.h>
#define flag '#'
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}LNODE,*Linklist;                   //定义单链表的结构体
Linklist Creath_Linklist()
{
    Linklist L=NULL;
    LNODE *s,*r=NULL;
    int e;
    scanf("%d",&e);                 //录入节点数据
    while(getchar()!=flag)
    {
        s=malloc(sizeof(LNODE));
        s->data=e;
        if(L==NULL)  L=s;
        else r->next=s;
        r=s;
        scanf("%d",&e);
    }                               //数据和节点指针的录入
    if(r!=NULL) r->next=NULL;
    return L;
}                                   //顺序建立单链表
void out(Linklist L)
{
    LNODE *p=L;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}                                   //单链表的输出
int Length_Linklist(Linklist L)
{
    LNODE *p=L;
    int i;
    if(p==NULL)  return 0;           //单链表为空
    i=1;
    while(p->next)
    {
        p=p->next;
        i++;
    }
    return i;
}                                   //求表长
LNODE *Get_Linklist(Linklist L,int i)
{
    LNODE *p=L;
    int j=1;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }                               //在范围内查找
    if(j==i)    return p;
    else return NULL;
}                                   //按序号查找
int *Locate_Linklist(Linklist L,int e)
{
    LNODE *p=L;
    int n,i;
    n=Length_Linklist(L);
    for(i=1;i<=n;i++)
    {
        if(p->data==e) return i;       //查找数据
        p=p->next;
    }
    return 0;
}                                      //按数据查找
int Insert_Linklist(Linklist L,int i,int e)
{
    LNODE *p,*s;
    p=Get_Linklist(L,i-1);
    if(p==NULL)
    {
        printf("参数i错\n");
        return 0;
    }                                   //排除空链表
    else
    {
        s=malloc(sizeof(LNODE));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return 1;
    }                                   //数据的插入
}                                       //插入数据
int delete(Linklist L,int i)
{
    Linklist p,s;
    p=Get_Linklist(L,i-1);
    if(p==NULL)
    {
        printf("第i-1个节点不存在\n");
        return -1;
    }                                    //空链表的排除
    else
        {
            if(p->next==NULL)
            {
                printf("第%d个节点不存在\n",i);
                return 0;
            }
            else
                {
                    s=p->next;
                    p->next=s->next;
                    free(s);
                    out(L);
                    return 1;
                }
        }
}                                          //数据删除
LNODE *alter_Linklist(Linklist L,int i,int e)           //修改元素
{
    LNODE *p=L;
    int j=1;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }                               //在范围内查找
    if(j==i)  p->data=e;
    else return NULL;
    return L;
}
int main()
{
    int a,i,n,e;
    Linklist L;
    LNODE *p;
    printf("请输入无头节点的单链表（结束输入请按#）\n");
    L=Creath_Linklist();
A:
    getchar();
    printf("\n请输入回车继续");
    getchar();
    system("cls");
    out(L);
    printf("****************************\n");
    printf("请数字选择对单链表的操作\n0：操作结束\n1：求表长\n2：按位置查找\n3：按数值查找\n4：插入操作\n5：删除操作\n6：修改元素\n");
    printf("****************************\n");
    printf("功能选择为：");
    scanf("%d",&a);
    switch(a)
    {
        case 0:printf("结束操作\n");break;
        case 1:                                                 //求单链表长度
            n=Length_Linklist(L);
            printf("单链表的长度为：%d\n",n);
            goto A;
        case 2:                                                 //按位置查找数据
        {
            printf("请输入查找节点i（第i个节点）:");
            scanf("%d",&i);
            p=Get_Linklist(L,i);
            if(p==NULL) printf("不存在第%d个节点\n",i);
            else printf("第%d个节点的值为：%d\n",i,p->data);
            goto A;
        }
        case 3:                                                 //按数据查找
        {
            printf("请输入查找值e:");
            scanf("%d",&e);
            i=Locate_Linklist(L,e);
            if(i==0)    printf("单链表内没有:%d\n",e);
            else    printf("%d在单链表第%d位\n",e,i);
            goto A;
        }
        case 4:                                                 //数据插入
        {
            n=Length_Linklist(L);
            printf("请输入插入位置i（第i位）:");
            scanf("%d",&i);
            if(i>n||i<=0)
            {
                printf("插入位置错误\n");
                goto A;
            }                                                   //排除插入位置错误
            printf("请输入插入数据e");
            scanf("%d",&e);
            n=Insert_Linklist(L,i,e);
            out(L);
            goto A;
        }
        case 5:                                                    //数据删除
        {
            printf("请输入删除位置i（第i位）:");
            scanf("%d",&i);
            n=delete(L,i);
            goto A;
        }
        case 6:
        {
            printf("请输入修改位置：");
            scanf("%d",&i);
            printf("请输入修改后的元素：");
            scanf("%d",&e);
            L=alter_Linklist(L,i,e);
            out(L);
            goto A;
        }
        default:                                                    //防止功能选择错误
            printf("选择错误，请重新输入\n");
            goto A;
    }
    return 0;
}
