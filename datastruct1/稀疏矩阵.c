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
    printf("������ϡ���������T.cn��");
    scanf("%d",&T.cn);
    printf("������ϡ���������T.rn��");
    scanf("%d",&T.rn);
    printf("������ϡ�����\n");
    for(i=0;i<T.cn;i++)                 //����ϡ�����
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
    printf("��Ԫ��˳���\n");                             //�����Ԫ��˳���
    printf("    | i  j  v  \n");
    printf("---------------\n");
    for(i=0;i<T.tn;i++)
        printf(" %d  | %d  %d  %d\n",i+1,T.data[i].row,T.data[i].col,T.data[i].value);
    printf("\n\n����Ԫ��˳���ԭΪ��ά����\n");
    for(i=0;i<T.cn;i++)                                     //����Ԫ��˳���ԭΪ��ά����
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
