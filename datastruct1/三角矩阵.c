#include<stdio.h>
int main()
{
    int M,N;
    printf("������������n��");
    scanf("%d",&N);
    int a[N][N],i,j,t=0;
    M=(N+1)*N/2;
    int k[M],m;
C:  printf("��ѡ�����Ǿ������ͣ�\n1.�����Ǿ���\n2.�����Ǿ���\nѡ��Ϊ��");
    scanf("%d",&m);
    switch(m)
    {
     case 1:
A:  for(i=0;i<N;i++)  //���ɾ���
    {
        printf("�����������Ǿ����%d�е�%d��Ԫ��:\n",i+1,N-i);
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
        {printf("���������Ǿ�������������\n");
        goto A;}
    }
    for(i=0;i<N;i++)
    for(j=i;j<N;j++)
    {
        k[t]=a[i][j];
        t++;
    }
    printf("ѹ������Ϊ��\n");
    for(i=0;i<M;i++)
        printf("%d  ",k[i]);
    printf("\n");
    t=0;
    printf("��ѹ���������ͷŵ������Ǿ���Ϊ��\n");
    for(i=0;i<N;i++)                    //��ѹ���������ͷ����Ǿ���
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
B:  for(i=0;i<N;i++)  //���ɾ���
    {
        printf("�����������Ǿ����%d�е�%d��Ԫ��:\n",i+1,i+1);
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
        {printf("���������Ǿ�������������\n");
        goto B;}
    }
    for(i=0;i<N;i++)
    for(j=0;j<=i;j++)
    {
        k[t]=a[i][j];
        t++;
    }
    printf("ѹ������Ϊ��\n");
    for(i=0;i<M;i++)
        printf("%d  ",k[i]);
    printf("\n");
    t=0;
    printf("��ѹ���������ͷŵ������Ǿ���Ϊ��\n");
    for(i=0;i<N;i++)                    //��ѹ���������ͷ����Ǿ���
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
    default:printf("ѡ�����������ѡ��\n");
    getchar();
    getchar();
    system("cls");
    goto C;
    }
    return 0;
}
