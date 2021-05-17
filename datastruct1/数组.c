#include<stdio.h>
int main()
{
    int a[100],N,i,e;
    printf("请输入数组长度\n");
    scanf("%d",&N);
    printf("请输入数组\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("增加元素\n");
    scanf("%d",&a[N]);
    N++;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("删除元素\n");
    a[N-1]=0;
    N--;
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("按数值查找元素\n");
    printf("请输入要查找的元素值：");
    scanf("%d",&e);
    for(i=0;i<N;i++)
    {
        if(a[i]==e)
        {
            printf("元素位置为：%d\n",i+1);
            break;
        }
    }
    printf("按位置查找元素\n");
    printf("请输入要查找的位置：");
    scanf("%d",&e);
    printf("该位置元素为：%d",a[e-1]);
    return 0;
}
