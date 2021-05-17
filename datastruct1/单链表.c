#include<stdio.h>
#define flag '#'
typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}LNODE,*Linklist;                   //���嵥����Ľṹ��
Linklist Creath_Linklist()
{
    Linklist L=NULL;
    LNODE *s,*r=NULL;
    int e;
    scanf("%d",&e);                 //¼��ڵ�����
    while(getchar()!=flag)
    {
        s=malloc(sizeof(LNODE));
        s->data=e;
        if(L==NULL)  L=s;
        else r->next=s;
        r=s;
        scanf("%d",&e);
    }                               //���ݺͽڵ�ָ���¼��
    if(r!=NULL) r->next=NULL;
    return L;
}                                   //˳����������
void out(Linklist L)
{
    LNODE *p=L;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}                                   //����������
int Length_Linklist(Linklist L)
{
    LNODE *p=L;
    int i;
    if(p==NULL)  return 0;           //������Ϊ��
    i=1;
    while(p->next)
    {
        p=p->next;
        i++;
    }
    return i;
}                                   //���
LNODE *Get_Linklist(Linklist L,int i)
{
    LNODE *p=L;
    int j=1;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }                               //�ڷ�Χ�ڲ���
    if(j==i)    return p;
    else return NULL;
}                                   //����Ų���
int *Locate_Linklist(Linklist L,int e)
{
    LNODE *p=L;
    int n,i;
    n=Length_Linklist(L);
    for(i=1;i<=n;i++)
    {
        if(p->data==e) return i;       //��������
        p=p->next;
    }
    return 0;
}                                      //�����ݲ���
int Insert_Linklist(Linklist L,int i,int e)
{
    LNODE *p,*s;
    p=Get_Linklist(L,i-1);
    if(p==NULL)
    {
        printf("����i��\n");
        return 0;
    }                                   //�ų�������
    else
    {
        s=malloc(sizeof(LNODE));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return 1;
    }                                   //���ݵĲ���
}                                       //��������
int delete(Linklist L,int i)
{
    Linklist p,s;
    p=Get_Linklist(L,i-1);
    if(p==NULL)
    {
        printf("��i-1���ڵ㲻����\n");
        return -1;
    }                                    //��������ų�
    else
        {
            if(p->next==NULL)
            {
                printf("��%d���ڵ㲻����\n",i);
                return 0;
            }
            else
                {
                    s=p->next;
                    p->next=s->next;
                    free(s);
                    out(L);
                    return 1;
                }
        }
}                                          //����ɾ��
LNODE *alter_Linklist(Linklist L,int i,int e)           //�޸�Ԫ��
{
    LNODE *p=L;
    int j=1;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }                               //�ڷ�Χ�ڲ���
    if(j==i)  p->data=e;
    else return NULL;
    return L;
}
int main()
{
    int a,i,n,e;
    Linklist L;
    LNODE *p;
    printf("��������ͷ�ڵ�ĵ��������������밴#��\n");
    L=Creath_Linklist();
A:
    getchar();
    printf("\n������س�����");
    getchar();
    system("cls");
    out(L);
    printf("****************************\n");
    printf("������ѡ��Ե�����Ĳ���\n0����������\n1�����\n2����λ�ò���\n3������ֵ����\n4���������\n5��ɾ������\n6���޸�Ԫ��\n");
    printf("****************************\n");
    printf("����ѡ��Ϊ��");
    scanf("%d",&a);
    switch(a)
    {
        case 0:printf("��������\n");break;
        case 1:                                                 //��������
            n=Length_Linklist(L);
            printf("������ĳ���Ϊ��%d\n",n);
            goto A;
        case 2:                                                 //��λ�ò�������
        {
            printf("��������ҽڵ�i����i���ڵ㣩:");
            scanf("%d",&i);
            p=Get_Linklist(L,i);
            if(p==NULL) printf("�����ڵ�%d���ڵ�\n",i);
            else printf("��%d���ڵ��ֵΪ��%d\n",i,p->data);
            goto A;
        }
        case 3:                                                 //�����ݲ���
        {
            printf("���������ֵe:");
            scanf("%d",&e);
            i=Locate_Linklist(L,e);
            if(i==0)    printf("��������û��:%d\n",e);
            else    printf("%d�ڵ������%dλ\n",e,i);
            goto A;
        }
        case 4:                                                 //���ݲ���
        {
            n=Length_Linklist(L);
            printf("���������λ��i����iλ��:");
            scanf("%d",&i);
            if(i>n||i<=0)
            {
                printf("����λ�ô���\n");
                goto A;
            }                                                   //�ų�����λ�ô���
            printf("�������������e");
            scanf("%d",&e);
            n=Insert_Linklist(L,i,e);
            out(L);
            goto A;
        }
        case 5:                                                    //����ɾ��
        {
            printf("������ɾ��λ��i����iλ��:");
            scanf("%d",&i);
            n=delete(L,i);
            goto A;
        }
        case 6:
        {
            printf("�������޸�λ�ã�");
            scanf("%d",&i);
            printf("�������޸ĺ��Ԫ�أ�");
            scanf("%d",&e);
            L=alter_Linklist(L,i,e);
            out(L);
            goto A;
        }
        default:                                                    //��ֹ����ѡ�����
            printf("ѡ���������������\n");
            goto A;
    }
    return 0;
}
