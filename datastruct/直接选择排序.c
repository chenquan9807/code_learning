#include<stdio.h>
#define max 50
void sort(int a[],int n)
{
    int i,j,min,t;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min])
                min=j;
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}
int main()
{
    int a[max],n,i;
    printf("�������鳤�ȣ�");
    scanf("%d",&n);
    printf("�������飺");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("��������飺");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
