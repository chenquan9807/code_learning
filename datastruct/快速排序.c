#include<stdio.h>
#define max 50
void sort(int a[],int left,int right)
{
    if(left>=right)
        return;
    int i=left;
    int j=right;
    int key=a[left];
    while(i<j)
    {
        while(i<j&&key<=a[j])
        {
            j--;
        }
        a[i]=a[j];
        while(i<j&&key>a[i])
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    sort(a,left,i-1);
    sort(a,i+1,right);
}
int main()
{
    int a[max],n,i;
    printf("输入数组长度：");
    scanf("%d",&n);
    printf("输入数组：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,0,n);
    printf("排序后数组：");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
