#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node                 //链表结构体的定义
{
    datatype data;
    struct node *next;
}Lnode,*Linklist;
Linklist Creat_Link(Linklist L)               //创建一个有头节点的链表
{
    Linklist H=NULL;
    Lnode *s,*r=NULL;
    int e;
    printf("请输入链表（有头节点）：\n");
    do
    {
        scanf("%d",&e);
        s=malloc(sizeof(Lnode));
        s->data=e;
        if(H==NULL) H=s;
        else   r->next=s;
        r=s;
    }while(getchar()!='\n');        //输入回车输入结束
    if(r!=NULL) r->next=L;       //链表末尾置空
    return H;
}
void Out_Linklist(Linklist H)       //链表输出
{
    Lnode *s;
    s=H->next;
    while(s!=H)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
Linklist Inversion_Linklist(Linklist H)         //单循环链表倒置
{
    int i,a[1000];
    Lnode *q=NULL,*p=NULL;
    q=H->next;
    p=H->next;
    for(i=0;q!=H;i++)                           //取出每个节点的数值
    {
        a[i]=q->data;
        q=q->next;
    }
    for(i--;p!=H;i--)                           //把数组的数倒序存入节点
    {
        p->data=a[i];
        p=p->next;
    }
    return H;
}
int main()
{
    Linklist H;
    H=malloc(sizeof(Lnode));
    H->next=NULL;
    H->next=Creat_Link(H);
    system("cls");
    printf("链表为：\n");
    Out_Linklist(H);
    H=Inversion_Linklist(H);
    printf("倒置的链表为：\n");
    Out_Linklist(H);
    return 0;
}
