#include<stdio.h>
int main()
{
    int a[100],N,i,e;
    printf("���������鳤��\n");
    scanf("%d",&N);
    printf("����������\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("����Ԫ��\n");
    scanf("%d",&a[N]);
    N++;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("ɾ��Ԫ��\n");
    a[N-1]=0;
    N--;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("����ֵ����Ԫ��\n");
    printf("������Ҫ���ҵ�Ԫ��ֵ��");
    scanf("%d",&e);
    for(i=0;i<N;i++)
    {
        if(a[i]==e)
        {
            printf("Ԫ��λ��Ϊ��%d\n",i+1);
            break;
        }
    }
    printf("��λ�ò���Ԫ��\n");
    printf("������Ҫ���ҵ�λ�ã�");
    scanf("%d",&e);
    printf("��λ��Ԫ��Ϊ��%d",a[e-1]);
    return 0;
}
