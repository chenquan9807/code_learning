#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node                 //����ṹ��Ķ���
{
    datatype data;
    struct node *next;
}Lnode,*Linklist;
Linklist Creat_Link(Linklist L)               //����һ����ͷ�ڵ������
{
    Linklist H=NULL;
    Lnode *s,*r=NULL;
    int e;
    printf("������������ͷ�ڵ㣩��\n");
    do
    {
        scanf("%d",&e);
        s=malloc(sizeof(Lnode));
        s->data=e;
        if(H==NULL) H=s;
        else   r->next=s;
        r=s;
    }while(getchar()!='\n');        //����س��������
    if(r!=NULL) r->next=L;       //����ĩβ�ÿ�
    return H;
}
void Out_Linklist(Linklist H)       //�������
{
    Lnode *s;
    s=H->next;
    while(s!=H)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
Linklist Inversion_Linklist(Linklist H)         //��ѭ��������
{
    int i,a[1000];
    Lnode *q=NULL,*p=NULL;
    q=H->next;
    p=H->next;
    for(i=0;q!=H;i++)                           //ȡ��ÿ���ڵ����ֵ
    {
        a[i]=q->data;
        q=q->next;
    }
    for(i--;p!=H;i--)                           //����������������ڵ�
    {
        p->data=a[i];
        p=p->next;
    }
    return H;
}
int main()
{
    Linklist H;
    H=malloc(sizeof(Lnode));
    H->next=NULL;
    H->next=Creat_Link(H);
    system("cls");
    printf("����Ϊ��\n");
    Out_Linklist(H);
    H=Inversion_Linklist(H);
    printf("���õ�����Ϊ��\n");
    Out_Linklist(H);
    return 0;
}
