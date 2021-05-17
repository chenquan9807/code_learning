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
    printf("请输入递增顺序表（长度小于100）:\n");
    do
    {
        scanf("%d",&e);
        L.data[L.len]=e;
        L.len=L.len+1;
    }while(getchar()!='\n');                    //输入回车输入结束
    if(L.len>=MAX) return ;
    return L;
}
int Search(Seqlist L,int a)
{
    int low=0,mid,high=L.len;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a==L.data[mid]) return mid+1;
        else if(a>L.data[mid]) low=mid+1;
        else high=mid-1;
    }
    printf("不存在该元素\n");
    return -1;
}
int main()
{
    int a,b;
    Seqlist L;
    L=Input_Seqlist(L);
    printf("请输入查找元素\n");
    scanf("%d",&a);
    b=Search(L,a);
    printf("该元素额位于第%d位\n",b);
    return 0;
}
