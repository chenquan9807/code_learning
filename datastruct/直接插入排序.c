#include<stdio.h>
#define max 50
void insert_sort(int a[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
            if(a[j]<a[i])
                break;
        if(j!=i-1)
        {
            int temp=a[i];
            for(k=i-1;k>j;k--)
                a[k+1]=a[k];
            a[k+1]=temp;
        }
    }
}
void main()
{
    int i,n;
    int a[max];
    printf("�������鳤�ȣ�");
    scanf("%d",&n);
    printf("�������飺");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("����ǰ���飺");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    insert_sort(a,n);
    printf("��������飺");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
