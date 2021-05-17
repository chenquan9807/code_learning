#include<stdio.h>
typedef int datatype;
typedef struct node                 //��ջ�Ķ���
{
    datatype data;
    struct node *next;
}Stacknode,*Linkstack;
Linkstack Init_Linkstack()          //��ջ�ÿ�
{
    return NULL;
}
int Empty_Linkstack(Linkstack top)  //�жϿ�ջ
{
    if(top==NULL) return 1;
    else return 0;
}
Linkstack Push_Linkstack(Linkstack top,datatype e)      //��ջ
{
    Stacknode *s;
    s=malloc(sizeof(Stacknode));
    s->data=e;
    s->next=top;
    top=s;
    return top;
}
Linkstack Pop_Linkstack(Linkstack top,datatype *e)      //��ջ
{
    Stacknode *p;
    if(top==NULL) {printf("��ջΪ��ջ\n");return NULL;}
    else
    {
        *e=top->data;
        p=top;
        top=top->next;
        free(p);
        printf("��ջ�ɹ�����ջԪ��Ϊ%d\n",*e);
        return top;
    }
}
datatype Gettop_Linkstack(Linkstack top)            //ȡջ��Ԫ��
{
    if(top==NULL)return NULL;
    else return top->data;
}
Linkstack Creat_Linkstack()
{
    int e;
    Stacknode *p;
    p=Init_Linkstack();
    do
    {
        scanf("%d",&e);
        p=Push_Linkstack(p,e);
    }while(getchar()!='\n');
    return p;
}
void out_Linkstack(Linkstack top)                   //�����ջ
{
    Stacknode *p=top;
    if(p==NULL)                                      //�ų�����ջ
    {
        printf("�������޷����\n");
        return -1;
    }
    printf("����ջΪ��\nջ��||");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("||ջ��\n");
}
void Num_Linkstack(Linkstack top,datatype e)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(s->data==e)
        {
            printf("��Ԫ�ؾ�ջ����%dλ\n",i);
            return;
        }
        s=s->next;
    }
    printf("��ջ�ڲ����ڸ���\n");
}
void Loc_Linkstack(Linkstack top,datatype e)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(i==e)
        {
            printf("��ջ��λ��Ϊ��%dλ��Ԫ��Ϊ%d\n",i,s->data);
            return;
        }
        s=s->next;
    }
    printf("��ջ�ڲ����ڸ�λ��\n");
}
Linkstack resort_Linkstack(Linkstack top,datatype e,int m)
{
    int i=0;
    Stacknode *s;
    s=top;
    while(s!=NULL)
    {
        i++;
        if(i==e)
        {
            s->data=m;
            out_Linkstack(top);
            return top;
        }
        s=s->next;
    }
    printf("��ջ�ڲ����ڸ�λ��\n");
    return top;
}
int main()
{
    int n,m;
    datatype e;
    Linkstack top;
    Stacknode *p;
    printf("������ջ\n");
    top=Creat_Linkstack();
    out_Linkstack(top);
    A:
    printf("****************************\n");
    printf("������ѡ�����ջ�Ĳ���\n0����������\n1���޸�Ԫ��\n2���жϿ�ջ\n3����ջ\n4����ջ\n5��ȡ��ջ��Ԫ��\n6�����ջ\n7����ֵ����\n8����λ�ò���\n");
    printf("****************************\n����ѡ��Ϊ��");
    scanf("%d",&n);
    switch(n)
    {
        case 0:printf("��������\n");return 0;
        case 1:
        {
            printf("������Ҫ�޸�λ�ã�");
            scanf("%d",&e);
            printf("����Ҫ�޸ĺ����ֵ��");
            scanf("%d",&m);
            top=resort_Linkstack(top,e,m);
            break;
        }
        case 2:
            {
                m=Empty_Linkstack(top);
                if(m==1)    printf("����ջΪ��ջ\n");
                else printf("����ջ��Ϊ��ջ\n");
                break;
            }
        case 3:
            {
                printf("��������ջԪ��e:   ");
                scanf("%d",&e);
                top=Push_Linkstack(top,e);
                out_Linkstack(top);
                break;
            }
        case 4:
            {
                top=Pop_Linkstack(top,&e);
                out_Linkstack(top);
                break;
            }
        case 5:
            {
                e=Gettop_Linkstack(top);
                if(e==NULL) printf("��ջΪ��ջ\n");
                else printf("ջ��Ԫ��Ϊ%d\n",e);
                break;
            }
        case 6:out_Linkstack(top);break;
        case 7:
            {
                printf("�����������ֵ:");
                scanf("%d",&e);
                Num_Linkstack(top,e);
                break;
            }
        case 8:
            {
                printf("������Ԫ�ؾ�ջ��λ��i:");
                scanf("%d",&e);
                Loc_Linkstack(top,e);
                break;
            }
        default:printf("ѡ�����������ѡ��\n");break;
    }
    getchar();
    printf("������س�����");
    getchar();
    system("cls");
    out_Linkstack(top);
    goto A;
}
