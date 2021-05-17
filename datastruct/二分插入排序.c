#include<stdio.h>
#define max 50
void sort(int a[],int n)
{
    int i,j;
    i=1;
    while(i<n)
    {
        int x=a[i];
        int high=0;
        int low=i-1;
        while(high<=low)
        {
            int mid=(high+low)/2;
            if(x<a[mid])
                low=mid-1;
            else
                high=mid+1;
        }
        for(j=i-1;j>=high;j--)
        {
            a[j+1]=a[j];
        }
        a[high]=x;
        i++;
    }
}
int main()
{
    int i,n;
    int a[max];
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
