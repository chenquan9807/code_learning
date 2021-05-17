#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int datatype;
typedef struct
{
    datatype data[MAXSIZE];
    int len;
}Seqlist;                               //将data和len封装成一个结构体
Seqlist *Init_Seqlist()
{
    Seqlist *L;
    L=malloc(sizeof(Seqlist));
    L->len=-1;
    return L;
}                                       //顺序表的初始化
int Insert_Seqlist(Seqlist *L,int i,datatype e)
{
    int j;
    if(L->len==MAXSIZE-1)
    {
        printf("表满溢出\n");
        return -1;
    }                                   //排除顺序表的溢出
    if(i<1||i>L->len+2)
    {
        printf("位置错误\n");
        return 0;
    }                                   //排除位置错误
    for(j=L->len;j>=i-1;j--)
        L->data[j+1]=L->data[j];        //数据插入
    L->data[i-1]=e;
    L->len++;
    printf("插入后的顺序表\n");
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }                                   //顺序表输出
    return 1;
}
int Dele_Seqlist(Seqlist *L,int i)
{
    int j;
    if(L->len==-1)
    {
        printf("表空溢出\n");
        return -1;
    }
    if(i<1||i>L->len+1)                //检查空表及删除位置的合法性
    {
        printf("不存在第%d个元素\n",i);
        return 0;
    }
    for(j=i;j<=L->len;j++)
        L->data[j-1]=L->data[j];       //删除位置后的顺序表向前移一位
    L->len--;
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }                                  //删除成功
    return 1;
}
int Locate_Seqlist(Seqlist *L,datatype e)
{
    int i=0;
    while(i<=L->len&&L->data[i]!=e)
        i++;                           //位置查找
    if(i>L->len)
        return -1;                     //查找失败
    else return i;                     //返回储存位置
}
int Get_Seqlist(Seqlist *L,int i)
{
    if(i<1||i>L->len+1)                //检查查找位置的合法性
    {
        printf("不存在第%d个元素\n",i);
        return 0;                      //查找失败
    }
    else
        return L->data[i-1];           //查找成功并返回数据
}
int main()
{
	int a,e,i,j,n,k;
    Seqlist *L=Init_Seqlist();
    L->len=-1;
    printf("请输入顺序表长度n(n<=10)\n");
    scanf("%d",&n);
    printf("请输入顺序表\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&L->data[j]);
        L->len++;
    }                                                   //输入数组
 A:
    printf("顺序表为\n");
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n****************************\n");
    printf("请输入相应的数字，完成操作：\n1：插入操作\n2：删除操作\n3：按值查找\n4：取表中元素\n5：结束\n");
    printf("****************************\n功能选择为：");
    scanf("%d",&a);
    switch(a)
    {
		case 1:
			{
				printf("请输入插入数字e：");
				scanf("%d",&e);
				printf("请输入数字%d插入位置i（第i位）：",e);
				scanf("%d",&i);
				k=Insert_Seqlist(L,i,e);
				break;                                         //数据插入的实现
			}
        case 2:
            {
                printf("请输入删除第几位元素（i的值）：");
                scanf("%d",&i);
                k=Dele_Seqlist(L,i);
                break;                                     // 数据删除的实现
            }
        case 3:
            {
                printf("请输入查找数字e：");
                scanf("%d",&e);
                k=Locate_Seqlist(L,e);
                if(k==-1)
                    printf("顺序表中没有元素%d\n",e);
                else
                    printf("%d点为顺序表第%d位元素\n",e,k+1);
                break;                                  //按值查找的实现
            }
        case 4:
            {
                printf("请输入提取元素位置i（第i位）：");
                scanf("%d",&i);
                k=Get_Seqlist(L,i);
                if(k!=0)
                    printf("第%d为元素为%d\n",i,k);
                break;                               //提取元素的实现
            }
		case 5: return 0;
        default :
            {
                printf("功能选择错误，请重新选择\n");
                break;
            }
    }
    getchar();
    printf("\n输入回车后继续");
    getchar();
    system("cls");
    goto A;
}
