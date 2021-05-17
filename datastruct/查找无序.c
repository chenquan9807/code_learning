#include<stdio.h>
#define MAX 100
typedef struct
{
    int len;
    int data[MAX];
}Seqlist;
Seqlist Input_Seqlist(Seqlist L)              //顺序表的输入（长度小于100）
{
    int e;
    L.len=0;
    printf("请输入顺序表（长度小于100）:\n");
    do
    {
        scanf("%d",&e);
        L.data[L.len]=e;
        L.len=L.len+1;
    }while(getchar()!='\n');                    //输入回车输入结束
    if(L.len>=MAX) return ;
    return L;
}
Seqlist sort_Seqlist(Seqlist L)
{
    int i,j,t;
    for(i=0;i<L.len;i++)
    {
        for(j=0;j<L.len;j++)
        {
            if(L.data[i]<L.data[j])
            {
                t=L.data[i];
                L.data[i]=L.data[j];
                L.data[j]=t;
            }
        }
    }
    return L;
}
int Search(Seqlist L,int a)
{
    int low=0,mid,high=L.len;
    while(low<=high)
    {
        mid=(low+high)/2+1;
        if(a==L.data[mid]) return mid+1;
        else if(a>L.data[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{
    int a,b;
    Seqlist L;
    L=Input_Seqlist(L);
    L=sort_Seqlist(L);
    printf("请输入查找元素\n");
    scanf("%d",&a);
    b=Search(L,a);
    if(b!=-1) printf("存在该元素\n");
    else printf("不存在该元素\n");
    return 0;
}
