#include<stdio.h>
#define MAX 100
typedef struct
{
    int len;
    int data[MAX];
}Seqlist;
Seqlist Input_Seqlist(Seqlist L)              //˳�������루����С��100��
{
    int e;
    L.len=0;
    printf("���������˳�������С��100��:\n");
    do
    {
        scanf("%d",&e);
        L.data[L.len]=e;
        L.len=L.len+1;
    }while(getchar()!='\n');                    //����س��������
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
    printf("�����ڸ�Ԫ��\n");
    return -1;
}
int main()
{
    int a,b;
    Seqlist L;
    L=Input_Seqlist(L);
    printf("���������Ԫ��\n");
    scanf("%d",&a);
    b=Search(L,a);
    printf("��Ԫ�ض�λ�ڵ�%dλ\n",b);
    return 0;
}
