#include<stdio.h>
#include<stdlib.h>
static int N,M;
void Out(int a[N][N])               //对称矩阵输出
{
    int j,i;
    printf("矩阵为：\n");
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    {
        printf("%-8d",a[i][j]);
        if(j==N-1)    printf("\n");
    }
}
int *Compress(int a[N][N])          //压缩对称矩阵
{
    int i,j,p[100],t=0;
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
    {
        p[t]=a[i][j];
        t++;
    }
    return p;
}
int main()
{
    printf("请输入矩阵阶数n：");
    scanf("%d",&N);
    int a[N][N],i=0,j=0,t=0,b[N][N],M;
    M=(1+N)*N/2;
    int *k;
 A:   for(i=0;i<N;i++)                //生成矩阵
    {
        printf("第%d行请输入%d个元素\n",i+1,N);
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<N;i++)                //生成矩阵
    {
        for(j=i;j<N;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                printf("输入矩阵不是对称矩阵，请重新输入\n");
                goto A;
            }
        }
    }
    Out(a);
    k=Compress(a);
    t=0;
    printf("压缩矩阵b为：\n");
    for(i=0;i<M;i++)
    {
        printf("%d  ",*(k+t));
        t++;
    }
    printf("\n");
    t=0;
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
    {
        b[i][j]=k[t];
        b[j][i]=b[i][j];
        t++;
    }
    printf("释放矩阵b为：\n");
    Out(b);
    return 0;
}
