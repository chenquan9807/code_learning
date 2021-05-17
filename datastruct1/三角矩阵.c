#include<stdio.h>
int main()
{
    int M,N;
    printf("请输入矩阵阶数n：");
    scanf("%d",&N);
    int a[N][N],i,j,t=0;
    M=(N+1)*N/2;
    int k[M],m;
C:  printf("请选择三角矩阵类型：\n1.上三角矩阵\n2.下三角矩阵\n选择为：");
    scanf("%d",&m);
    switch(m)
    {
     case 1:
A:  for(i=0;i<N;i++)  //生成矩阵
    {
        printf("请输入上三角矩阵第%d行的%d个元素:\n",i+1,N-i);
    for(j=0;j<N;j++)
    {
        if(j<i) a[i][j]=0;
        else
        {
            scanf("%d",&a[i][j]);
        }
    }
    }
    for(i=0;i<N;i++)
    for(j=0;j<i;j++)
    {
        if(a[i][j]!=0)
        {printf("不是上三角矩阵请重新输入\n");
        goto A;}
    }
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
    {
        k[t]=a[i][j];
        t++;
    }
    printf("压缩矩阵为：\n");
    for(i=0;i<M;i++)
        printf("%d  ",k[i]);
    printf("\n");
    t=0;
    printf("从压缩矩阵中释放的上三角矩阵为：\n");
    for(i=0;i<N;i++)                    //从压缩矩阵中释放三角矩阵
    {
    for(j=0;j<N;j++)
    {
        if(j<i) printf("*       ");
        else
        {
            printf("%-8d",k[t]);
            t++;
        }
    }
    printf("\n");
    }
    break;
    case 2:
B:  for(i=0;i<N;i++)  //生成矩阵
    {
        printf("请输入下三角矩阵第%d行的%d个元素:\n",i+1,i+1);
    for(j=0;j<N;j++)
    {
        if(j>i) a[i][j]=0;
        else
        {
            scanf("%d",&a[i][j]);
        }
    }
    }
    for(i=0;i<N;i++)
    for(j=i+1;j<N;j++)
    {
        if(a[i][j]!=0)
        {printf("不是下三角矩阵请重新输入\n");
        goto B;}
    }
    for(i=0;i<N;i++)
    for(j=0;j<=i;j++)
    {
        k[t]=a[i][j];
        t++;
    }
    printf("压缩矩阵为：\n");
    for(i=0;i<M;i++)
        printf("%d  ",k[i]);
    printf("\n");
    t=0;
    printf("从压缩矩阵中释放的下三角矩阵为：\n");
    for(i=0;i<N;i++)                    //从压缩矩阵中释放三角矩阵
    {
    for(j=0;j<N;j++)
    {
        if(j>i) printf("*       ");
        else
        {
            printf("%-8d",k[t]);
            t++;
        }
    }
    printf("\n");
    }break;
    default:printf("选择错误，请重新选择\n");
    getchar();
    getchar();
    system("cls");
    goto C;
    }
    return 0;
}
