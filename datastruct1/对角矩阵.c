#include<stdio.h>
int main()
{
    int i,j,N,t=0,n,m,o,p=0;
    printf("������������N��");
    scanf("%d",&N);
A:  printf("������ԽǾ���Ĵ���n��");
    scanf("%d",&n);
    if(n%2==0)
    {
        printf("������Ϊ����������������\n");
        goto A;
    }
    o=(n-1)/2;
    m=N*N-((N-o)*(N-o-1));
    int a[N][N],k[ m];
    printf("����������˳������%d��Ԫ��\n",m);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i>j+o||j>i+o) a[i][j]=0;
            else
            {
                scanf("%d",&a[i][j]);
                k[t]=a[i][j];
                t++;
            }
        }
    }
    t=0;
     for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i>j+o||j>i+o) printf("%-5d",p);
            else
            {
                printf("%-5d",k[t]);
                t++;
            }
        }
        printf("\n");
    }
    return 0;
}
