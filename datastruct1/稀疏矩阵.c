#include<stdio.h>
#define MAX_SIZE 101
typedef  int elemtype;
typedef struct
{
    int row;
    int col;
    elemtype value;
}Triple;
typedef struct
{
    int rn;
    int cn;
    int tn;
    Triple data[MAX_SIZE];
}Tmatrix;
int main()
{
    int i,j,p=0,q=0;
    float k;
    Tmatrix T;
    T.tn=0;
    printf("请输入稀疏矩阵行数T.cn：");
    scanf("%d",&T.cn);
    printf("请输入稀疏矩阵列数T.rn：");
    scanf("%d",&T.rn);
    printf("请输入稀疏矩阵\n");
    for(i=0;i<T.cn;i++)                 //输入稀疏矩阵
    for(j=0;j<T.rn;j++)
    {
        scanf("%d",&T.data[T.tn].value);
        if(T.data[T.tn].value!=0)
        {
            T.data[T.tn].row=i;
            T.data[T.tn].col=j;
            T.tn++;
        }
    }
    printf("三元组顺序表\n");                             //输出三元组顺序表
    printf("    | i  j  v  \n");
    printf("---------------\n");
    for(i=0;i<T.tn;i++)
        printf(" %d  | %d  %d  %d\n",i+1,T.data[i].row,T.data[i].col,T.data[i].value);
    printf("\n\n将三元组顺序表还原为二维矩阵\n");
    for(i=0;i<T.cn;i++)                                     //将三元组顺序表还原为二维矩阵
    {
    for(j=0;j<T.rn;j++)
    {
        if(i==T.data[p].row&&j==T.data[p].col)
        {
            printf("%-3d",T.data[p].value);
            p++;
        }
        else printf("%-3d",q);
    }
    printf("\n");
    }
    return 0;
}
