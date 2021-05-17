#include<stdio.h>
#define MAX 100
typedef int datatype;
typedef struct                              //顺序表结构体的定义
{
    datatype data[MAX];
    int len;
}SeqList;
SeqList *Init_SeqList()                     //顺序表的初始化
{
    SeqList *L;
    L=malloc(sizeof(SeqList));
    L->len=-1;
    return L;
}
int Insert_SeqList(SeqList *L,int i,datatype e)//顺序表的插入
{
    int j;
    if(L->len==MAX) return -1;                  //判断插入位置是否满足要求
    if(i<1||i>L->len+2)return 0;                //判断插入位置是否满足要求
    for(j=L->len;j>=i-1;j--)
        L->data[j+1]=L->data[j];
    L->data[i-1]=e;
    L->len++;
    return 1;
}
int Delate_SeqList(SeqList *L,int i)            //顺序表某一位置的删除
{
    int j;
    if(i<1||i>L->len) return -1;
    for(j=i-1;j<=L->len;j++)
        L->data[j]=L->data[j+1];
    L->len--;
    return 1;
}
int Findnum_SeqList(SeqList *L,int i)            //按数值查找
{
    int j,t=-1;
    for(j=0;j<=L->len;j++)
    {
        if(L->data[j]==i)
            t=j+1;
    }
    if(t==-1) return -1;                        //顺序表内没有该数值
    return t;
}
int Findpos_SeqList(SeqList *L,int i)           //按位置查找
{
    if(i<1||i>L->len+1) return -1;              //位置超出顺序表范围
    return L->data[i-1];
}
SeqList *Input_SeqList(SeqList *L)              //顺序表的输入（长度小于100）
{
    int i;
    datatype e;
    L->len=0;
    printf("请输入顺序表（长度小于100）:\n");
    do
    {
        scanf("%d",&e);
        L->data[L->len]=e;
        L->len++;
    }while(getchar()!='\n');                    //输入回车输入结束
    if(L->len>=MAX) return -1;
    return L;
}
int out_SeqList(SeqList *L)             //顺序表的输出
{
    printf("顺序表为:\n");
    int j;
    for(j=0;j<L->len;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int i,t,m;
    datatype e;
    SeqList *L=Init_SeqList();
    L=Input_SeqList(L);
 A:
    system("cls");
    m=out_SeqList(L);
    printf("************************\n");
    printf("菜单：\n0：退出程序\n1：插入\n2：删除\n3：按数值查找\n4：按位置查找\n");
    printf("************************\n功能选择为：");
    scanf("%d",&t);
    switch(t)
    {
    case 0:
        return 0;
    case 1:
        printf("请输入插入位置：");
        scanf("%d",&i);
        printf("请输入插入数值大小：");
        scanf("%d",&e);
        m=Insert_SeqList(L,i,e);
        if(m==-1||m==0)
            {printf("位置错误\n");break;}
        m=out_SeqList(L);
            break;
    case 2:
        printf("请输入删除位置：");
        scanf("%d",&i);
        m=Delate_SeqList(L,i);
        if(m==-1){printf("位置错误\n");break;}
        m=out_SeqList(L);
        break;
    case 3:
        printf("请输入查找数值：");
        scanf("%d",&i);
        m=Findnum_SeqList(L,i);
        if(m==-1){printf("顺序表内没有该数值\n");break;}
        printf("数值%d的位置为：%d\n",i,m);
        break;
    case 4:
        printf("请输入查找位置：");
        scanf("%d",&i);
        m=Findpos_SeqList(L,i);
        if(m==-1) {printf("位置错误\n");break;}
        printf("第%d位的数值为:   %d\n",i,m);
        break;
        default:printf("输入错误请重新输入\n");
    }
    printf("\n\n输入回车继续");
    getchar();
    getchar();
    goto A;
}
