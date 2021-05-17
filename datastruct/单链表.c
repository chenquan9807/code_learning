#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node                 //����ṹ��Ķ���
{
    datatype data;
    struct node *next;
}Lnode,*Linklist;
Linklist Creat_Link()               //����һ����ͷ�ڵ������
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
    if(r!=NULL) r->next=NULL;       //����ĩβ�ÿ�
    return H;
}
void Out_Linklist(Linklist H)       //�������
{
    printf("����Ϊ��\n");
    Lnode *s;
    s=H->next;
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
Lnode *Findpos_LInklist(Linklist H,int i)       //��λ�ò��������һ���ڵ�
{
    int j=0;
    Lnode *p=H;
    while(p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i) return p;                          //�ж��������Ƿ��иýڵ�
    else return NULL;
}
int Findnum_LInklist(Linklist H,datatype e)     //����ֵ���������һ���ڵ�
{
    int n=0;
    Lnode *p=H;
    while(p!=NULL&&p->data!=e)
     {
          p=p->next;
          n++;
     }
    if(p==NULL)return -1;                       //�ж��������Ƿ��и���ֵΪe�Ľڵ�
    return n;
}
int Insert_Linklist(Linklist H,int i,datatype e)//�������ڲ���һ���ڵ�
{
    Lnode *p,*s;
    p=Findpos_LInklist(H,i-1);
    if(p==NULL)     return -1;                  //����λ�õ�ǰһ���ڵ㲻��Ϊ��
     else
     {
         s=malloc(sizeof(Lnode));
         s->data=e;
         s->next=p->next;
         p->next=s;
         return 1;
     }
}
int Delete_Linklist(Linklist H,int i)           //ɾ��һ���ڵ�
{
    Lnode *p,*s;
    p=malloc(sizeof(Lnode));
    p=Findpos_LInklist(H,i-1);
    if(p==NULL) return -1;                      //ɾ��λ�õ�ǰһ���ڵ㲻��Ϊ��
    else
    {
        if(p->next==NULL) return -1;            //ɾ���Ľڵ�������
        else
        {
            s=p->next;
            p->next=s->next;
            free(s);
            return 0;
        }
    }
}
int main()
{
    int i,m,t;
    datatype e;
    Linklist H;
    Lnode *p;
    H=malloc(sizeof(Lnode));
    H->next=NULL;
    H->next=Creat_Link();
    A:
    system("cls");
    Out_Linklist(H);
    printf("************************\n");
    printf("�˵���\n0���˳�����\n1����λ�ò���\n2������ֵ����\n3������\n4��ɾ��\n");
    printf("************************\n����ѡ��Ϊ��");
    scanf("%d",&t);
    switch(t)
    {
    case 0:return 0;
    case 1:
        printf("���������λ�ã�");
        scanf("%d",&i);
        p=Findpos_LInklist(H,i);
        if(p==NULL) {printf("λ�ô���\n");break;}
        printf("��%dλ����ֵΪ:   %d\n",i,p->data);
        break;
    case 2:
        printf("�����������ֵ��");
        scanf("%d",&e);
        m=Findnum_LInklist(H,e);
        if(m==-1) {printf("������û�������\n");break;}
        printf("��ֵ%d��λ��Ϊ��%d\n",e,m);
        break;
    case 3:
        printf("���������λ�ã�");
        scanf("%d",&i);
         printf("�����������ֵ��");
        scanf("%d",&e);
        m=Insert_Linklist(H,i,e);
        if(m==-1){printf("λ�ô���\n");break;}
        Out_Linklist(H);
        break;
    case 4:
        printf("������ɾ��λ�ã�");
        scanf("%d",&i);
        m=Delete_Linklist(H,i);
        if(m==-1){printf("λ�ô���\n");break;}
        Out_Linklist(H);
        break;
    default:printf("�����������������\n");
    }
    printf("\n\n����س�����");
    getchar();
    getchar();
    goto A;
}
