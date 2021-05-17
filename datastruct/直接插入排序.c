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
    printf("输入数组长度：");
    scanf("%d",&n);
    printf("输入数组：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("排序前数组：");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    insert_sort(a,n);
    printf("排序后数组：");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
