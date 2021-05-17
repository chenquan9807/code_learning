#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node                 //链表结构体的定义
{
    datatype data;
    struct node *next;
}Lnode,*Linklist;
Linklist Creat_Link()               //创建一个有头节点的链表
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
    if(r!=NULL) r->next=NULL;       //链表末尾置空
    return H;
}
void Out_Linklist(Linklist H)       //链表输出
{
    printf("链表为：\n");
    Lnode *s;
    s=H->next;
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
Lnode *Findpos_LInklist(Linklist H,int i)       //按位置查找链表的一个节点
{
    int j=0;
    Lnode *p=H;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i) return p;                          //判断链表内是否有该节点
    else return NULL;
}
int Findnum_LInklist(Linklist H,datatype e)     //按数值查找链表的一个节点
{
    int n=0;
    Lnode *p=H;
    while(p!=NULL&&p->data!=e)
     {
          p=p->next;
          n++;
     }
    if(p==NULL)return -1;                       //判断链表内是否有该数值为e的节点
    return n;
}
int Insert_Linklist(Linklist H,int i,datatype e)//向链表内插入一个节点
{
    Lnode *p,*s;
    p=Findpos_LInklist(H,i-1);
    if(p==NULL)     return -1;                  //插入位置的前一个节点不能为空
     else
     {
         s=malloc(sizeof(Lnode));
         s->data=e;
         s->next=p->next;
         p->next=s;
         return 1;
     }
}
int Delete_Linklist(Linklist H,int i)           //删除一个节点
{
    Lnode *p,*s;
    p=malloc(sizeof(Lnode));
    p=Findpos_LInklist(H,i-1);
    if(p==NULL) return -1;                      //删除位置的前一个节点不能为空
    else
    {
        if(p->next==NULL) return -1;            //删除的节点必须存在
        else
        {
            s=p->next;
            p->next=s->next;
            free(s);
            return 0;
        }
    }
}
int main()
{
    int i,m,t;
    datatype e;
    Linklist H;
    Lnode *p;
    H=malloc(sizeof(Lnode));
    H->next=NULL;
    H->next=Creat_Link();
    A:
    system("cls");
    Out_Linklist(H);
    printf("************************\n");
    printf("菜单：\n0：退出程序\n1：按位置查找\n2：按数值查找\n3：插入\n4：删除\n");
    printf("************************\n功能选择为：");
    scanf("%d",&t);
    switch(t)
    {
    case 0:return 0;
    case 1:
        printf("请输入查找位置：");
        scanf("%d",&i);
        p=Findpos_LInklist(H,i);
        if(p==NULL) {printf("位置错误\n");break;}
        printf("第%d位的数值为:   %d\n",i,p->data);
        break;
    case 2:
        printf("请输入查找数值：");
        scanf("%d",&e);
        m=Findnum_LInklist(H,e);
        if(m==-1) {printf("链表中没有这个数\n");break;}
        printf("数值%d的位置为：%d\n",e,m);
        break;
    case 3:
        printf("请输入插入位置：");
        scanf("%d",&i);
         printf("请输入插入数值：");
        scanf("%d",&e);
        m=Insert_Linklist(H,i,e);
        if(m==-1){printf("位置错误\n");break;}
        Out_Linklist(H);
        break;
    case 4:
        printf("请输入删除位置：");
        scanf("%d",&i);
        m=Delete_Linklist(H,i);
        if(m==-1){printf("位置错误\n");break;}
        Out_Linklist(H);
        break;
    default:printf("输入错误请重新输入\n");
    }
    printf("\n\n输入回车继续");
    getchar();
    getchar();
    goto A;
}
