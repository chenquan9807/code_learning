#include<stdio.h>
#define max 40
void sort(int a[],int n)
{
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
}
int main()
{
    int a[max],n,i;
    printf("输入数组长度：");
    scanf("%d",&n);
    printf("输入数组：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("排序后数组：");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
